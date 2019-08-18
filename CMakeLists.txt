cmake_minimum_required(VERSION 2.8.3)
project(vio)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g")


find_package(OpenCV REQUIRED)
find_package(Eigen3)
include_directories(
  ${EIGEN3_INCLUDE_DIR}
  ./Thirdparty
)

SET(SRC 
  main.cpp)

add_executable(VIO ${SRC})
target_link_libraries(VIO ${OpenCV_LIBS} "/home/megvii/code/zdf_ws/src/cam_odo_cal-dev/Thirdparty/Sophus/build/libSophus.so") 

