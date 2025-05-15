
# ros-semantic-segmentation (modified version)

This repository is based on the original project [`ros-semantic-segmentation`](https://github.com/dheera/ros-semantic-segmentation), developed by Dheera Venkatraman. 
The main goal of this modified version is to **adapt and improve the functionality of the original project**, solving compatibility issues and adding new capabilities to ease usage and visualization.

## Overview of Modifications

- Updated dependencies for compatibility with Python 3, TensorFlow, and ROS Noetic 
- Fixed runtime errors related to model loading and message publishing 
- Created a new segmentation node to support additional pretrained models (e.g. `mnv2_coco`) 
- Refactored code structure for improved readability and debugging 
- Modified category files to improve class recognition accuracy (e.g. traffic lights, people, vehicles) 
- Enabled RViz-based semantic visualization through ROS topics `/semantic` and `/semantic_color`

## How to use

1. Clone the repository:

```bash
git clone https://github.com/SantiPR00/Ros-Semantic-Segmentation_Modificado.git
cd Ros-Semantic-Segmentation_Modificado
```

2. Install required dependencies:

Make sure you have ROS installed (Noetic recommended), along with TensorFlow and OpenCV.

3. Build the workspace:

```bash
cd ~/catkin_ws
catkin_make
source devel/setup.bash
```

4. Launch the segmentation:

```bash
rosrun semantic_segmentation nodes/segmentation_node.py _model:=mnv2_coco2017_driving_513
```

5. Visualize in RViz using the `/semantic` and `/semantic_color` topics.

## Dataset and models used

- Pretrained models based on [MobileNetV2 COCO](https://github.com/tensorflow/models/blob/master/research/deeplab/g3doc/model_zoo.md)
- Test image included in the root folder (`imagen_prueba.png`)
- Real-time semantic output via ROS topics

## Folder structure

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

## Notes

This version has been used in a practical evaluation of multiple semantic segmentation approaches using ROS, and demonstrates a functional and extendable integration for both RGB-based and multi-class segmentation systems.

## Author

This repository has been modified as part of a Bachelor's Thesis project focused on the exploration, adaptation, and analysis of semantic segmentation tools integrated into ROS.

**Modified by:** [SantiPR00](https://github.com/SantiPR00)
