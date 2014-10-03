cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
set(ROS_BUILD_TYPE RelWithDebInfo)
rosbuild_init()

find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})

rosbuild_gensrv()

add_definitions(-DQT_NO_KEYWORDS -DQT_QMAKE_EXECUTABLE=/usr/bin/qmake-qt4)
qt4_wrap_cpp(MOC_FILES
  include/estopControl.h
)
set(SOURCE_FILES
  src/estopControl.cpp
  include/estopControl.h
  plugin_description.xml
manifest.xml
mainpage.dox
Makefile
  ${MOC_FILES}
)

include_directories(/usr/include/eigen3 /usr/include/)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
rosbuild_add_library(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
