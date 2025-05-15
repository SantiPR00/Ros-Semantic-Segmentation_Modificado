
# ros-semantic-segmentation (modified version)

This repository is based on the original project [`ros-semantic-segmentation`](https://github.com/dheera/ros-semantic-segmentation), developed by Dheera Venkatraman. 
The main goal of this modified version is to **adapt and improve the functionality of the original project**, solving compatibility issues and adding new capabilities to ease usage and visualization.

---

## Improvements and modifications made

- **Updated dependencies** for compatibility with current versions of Python, TensorFlow, and ROS (Noetic).
- **Fixed execution errors** that prevented the main node from running.
- **Refactored code** and scripts for better debugging and organization.
- **Created a new segmentation node** adapted to models with different categories (`mnv2_coco`).
- **Fully working RViz visualization**, without requiring physical hardware.
- **Category file modifications** to improve semantic precision (e.g., recognizing traffic lights, people, cars, etc.).
- **Separated model versions**, allowing the use of different folders and configurations.

---

## How to run

1. **Clone the repository:**

```bash
git clone https://github.com/SantiPR00/Ros-Semantic-Segmentation_Modificado.git
cd Ros-Semantic-Segmentation_Modificado
```

2. **Install required dependencies:**

Make sure you have ROS installed (Noetic recommended), along with TensorFlow and OpenCV.

3. **Build the workspace:**

```bash
cd ~/catkin_ws
catkin_make
source devel/setup.bash
```

4. **Launch the segmentation:**

```bash
rosrun semantic_segmentation nodes/segmentation_node.py _model:=mnv2_coco2017_driving_513
```

5. **Visualize in RViz** using the `/semantic` and `/semantic_color` topics.

---

## Dataset and models used

- Pretrained models based on [MobileNetV2 COCO](https://github.com/tensorflow/models/blob/master/research/deeplab/g3doc/model_zoo.md)
- Test image included in the root folder (`imagen_prueba.png`)
- Real-time semantic output via ROS topics

---

## Relevant repository structure

```
semantic_segmentation/
├── models/
│   ├── driveable100k/
│   └── mnv2_coco/
├── nodes/
│   ├── segmentation_node.py
│   └── segmentation_node_coco.py
├── launch/
├── scripts/
```

---

## Reference to the original repository

This work is based on the repository:

- [https://github.com/dheera/ros-semantic-segmentation](https://github.com/dheera/ros-semantic-segmentation)

Original author: Dheera Venkatraman

---

## Author of this version

This repository has been modified as part of a Bachelor's Thesis project focused on the exploration, adaptation, and analysis of semantic segmentation tools integrated into ROS.

**Modified by:** [SantiPR00](https://github.com/SantiPR00)
