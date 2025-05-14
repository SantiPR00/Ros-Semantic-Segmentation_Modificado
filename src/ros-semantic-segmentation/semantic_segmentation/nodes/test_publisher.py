#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

def publish_image():
    rospy.init_node('image_publisher_node', anonymous=True)
    image_pub = rospy.Publisher('/image_raw', Image, queue_size=1)
    bridge = CvBridge()

    # Cargar la imagen desde el directorio de trabajo
    img_path = '/home/santi/catkin_ws/imagen_prueba.png'
    img = cv2.imread(img_path)

    if img is None:
        rospy.logerr("La imagen no pudo ser cargada.")
        return

    rate = rospy.Rate(1)  # Publica la imagen a 1 Hz

    while not rospy.is_shutdown():
        # Convertir la imagen a mensaje ROS
        img_msg = bridge.cv2_to_imgmsg(img, encoding="bgr8")
        image_pub.publish(img_msg)
        rospy.loginfo("Imagen publicada en /image_raw")
        rate.sleep()

if __name__ == '__main__':
    try:
        publish_image()
    except rospy.ROSInterruptException:
        pass

