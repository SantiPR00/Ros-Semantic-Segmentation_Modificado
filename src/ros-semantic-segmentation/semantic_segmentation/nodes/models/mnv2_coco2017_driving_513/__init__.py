#!/usr/bin/env python3

import json
import os
import numpy as np
import tensorflow as tf
import time


PATH = os.path.dirname(__file__)
MODEL_FILENAME = "graph.pb"
CATEGORIES_FILENAME = "categories.json"
INPUT_SIZE = 513
INPUT_TENSOR_NAME = "ImageTensor:0"
OUTPUT_TENSOR_NAME = "SemanticPredictions:0"

class Model(object):
    def __init__(self):
        # Cambio en la forma de cargar el grafo para TensorFlow 2.x, ya que se está utilizando compatibilidad con TensorFlow v1
        self.graph = tf.Graph()
        with self.graph.as_default():
            # Usamos tf.io.gfile.GFile para cargar el archivo del grafo
            with tf.io.gfile.GFile(os.path.join(PATH, MODEL_FILENAME), 'rb') as f:
                graph_def = tf.compat.v1.GraphDef()
                graph_def.ParseFromString(f.read())
                # Importamos el grafo de manera compatible con TensorFlow 2.x
                tf.import_graph_def(graph_def, name='')

        # Cambio: Usamos tf.compat.v1.Session para mantener la compatibilidad con el código original en TensorFlow v2
        self.session = tf.compat.v1.Session(graph=self.graph)

        # Mantenimiento del método para cargar las categorías y mapa de colores
        with open(os.path.join(PATH, CATEGORIES_FILENAME)) as f:
            self._categories = json.loads(f.read())
            self._color_map = np.array([category["color"] for category in self._categories], dtype=np.uint8)

    @property
    def color_map(self):
        return self._color_map

    @property
    def categories(self):
        return self._categories

    def infer(self, images):
        # Cambio: Redimensionamos las imágenes de entrada al tamaño esperado por el modelo (INPUT_SIZE)
        resized_images = [tf.image.resize(image, (INPUT_SIZE, INPUT_SIZE)).numpy() for image in images]

        # Ejecutar la inferencia con la sesión de TensorFlow
        seg_maps = self.session.run(
            OUTPUT_TENSOR_NAME,
            feed_dict={INPUT_TENSOR_NAME: resized_images}
        )

        return seg_maps

