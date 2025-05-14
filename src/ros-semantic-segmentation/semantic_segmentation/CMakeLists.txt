cmake_minimum_required(VERSION 3.0.2)
project(semantic_segmentation)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs   # Asegúrate de incluir esto si tu nodo lo utiliza
  cv_bridge     # Asegúrate de incluir esto si tu nodo lo utiliza
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(PROGRAMS
  nodes/segmentation_node.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY
  nodes/models
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

