cmake_minimum_required(VERSION 3.5)
project(mser)

set(CMAKE_CXX_STANDARD 11)

# OpenVC3 required
set(CMAKE_PREFIX_PATH /home/cuizhou/Downloads/opencv-3.3.0/build_cuda)
find_package(OpenCV 3.3.0 REQUIRED)


add_executable(main main.cpp MyMserRegionProposal.cpp MyMserRegionProposal.h fileOperator.cpp MyMatOperation.cpp MyMatOperation.h)
target_link_libraries(main ${OpenCV_LIBS} glog)

