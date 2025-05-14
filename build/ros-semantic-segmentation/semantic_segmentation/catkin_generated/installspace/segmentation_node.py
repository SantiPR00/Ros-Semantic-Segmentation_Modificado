#!/usr/bin/env python3

import sys
import os
import numpy as np
import rospy
import cv_bridge
from sensor_msgs.msg import Image

# Añadir la ruta al paquete semantic_segmentation
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../..')))

def on_image(msg):
    on_image.last_image = msg
on_image.last_image = None

class RoadSegmentationNode:
    def __init__(self):
        # Inicializa el nodo
        rospy.init_node('road_segmentation_node')
        rospy.loginfo("Iniciando nodo de segmentación de carreteras...")

        # Crea una instancia de CvBridge
        self.bridge = cv_bridge.CvBridge()

        # Obtener parámetros
        MODEL = rospy.get_param('~model', 'mnv2_coco2017_driving_513')
        TOPIC_IMAGE = rospy.get_param('~topic_image', 'image_raw')
        TOPIC_SEMANTIC = rospy.get_param('~topic_semantic', 'semantic')
        TOPIC_SEMANTIC_COLOR = rospy.get_param('~topic_semantic_color', 'semantic_color')
        RATE = rospy.get_param('~rate', 30.0)

        # Suscripciones
        sub_image = rospy.Subscriber(TOPIC_IMAGE, Image, on_image)
        self.pub_semantic = rospy.Publisher(TOPIC_SEMANTIC, Image, queue_size=1)
        self.pub_semantic_color = rospy.Publisher(TOPIC_SEMANTIC_COLOR, Image, queue_size=1)

        # Cargar el modelo
        try:
            self.model = getattr(__import__('semantic_segmentation.nodes.models', globals(), locals(), fromlist=[MODEL]), MODEL).Model()
            rospy.set_param("semantic_categories", self.model.categories)
            rospy.loginfo("Modelo cargado correctamente.")
        except Exception as e:
            rospy.logerr(f"Error al cargar el modelo: {e}")

        rate = rospy.Rate(RATE)

        while not rospy.is_shutdown():
            rate.sleep()

            if on_image.last_image is None:
                continue

            # Procesar la imagen
            header = on_image.last_image.header
            try:
                cv_image = self.bridge.imgmsg_to_cv2(on_image.last_image, "bgr8")
                rospy.loginfo(f"Imagen recibida con dimensiones: {cv_image.shape}")
            except Exception as e:
                rospy.logerr(f"Error al convertir la imagen: {e}")
                continue

            # Inferencia del modelo
            try:
                semantic = self.model.infer([cv_image])[0]
                rospy.loginfo(f"Segmentación obtenida con valores únicos: {np.unique(semantic)}")
            except Exception as e:
                rospy.logerr(f"Error durante la inferencia: {e}")
                continue  # Salta al siguiente bucle si hay un error

            # Publicar la segmentación semántica en blanco y negro
            if self.pub_semantic.get_num_connections() > 0:
                try:
                    m = self.bridge.cv2_to_imgmsg(semantic.astype(np.uint8), encoding='mono8')
                    m.header.stamp = header.stamp
                    self.pub_semantic.publish(m)
                    rospy.loginfo("Publicada segmentación en /semantic")
                except Exception as e:
                    rospy.logerr(f"Error al publicar /semantic: {e}")

            # Publicar la imagen segmentada con el mapa de colores
            if self.pub_semantic_color.get_num_connections() > 0:
                try:
                    semantic_color = self.model.color_map[semantic.astype(np.uint8)]
                    m = self.bridge.cv2_to_imgmsg(semantic_color, encoding='rgb8')
                    m.header.stamp = header.stamp
                    self.pub_semantic_color.publish(m)
                    rospy.loginfo("Publicada segmentación en /semantic_color")
                except Exception as e:
                    rospy.logerr(f"Error al publicar /semantic_color: {e}")

if __name__ == "__main__":
    try:
        RoadSegmentationNode()
    except rospy.ROSInterruptException:
        pass

