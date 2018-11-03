cmake_minimum_required(VERSION 3.5)
project(opencvtoolbox)

# c++11 required
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")  
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++0x")
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#SET(CUDA_TOOLKIT_ROOT_DIR "/usr/local/cuda-6.5")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/usr/local")
endif ()

# OpenVC3 required
set(CMAKE_PREFIX_PATH /home/cuizhou/Downloads/opencv-3.3.0/build_cuda)
find_package(OpenCV 3.2.0 REQUIRED)

# sources to be compiled
set(SOURCE_FILES
        Parseavi.cpp
        )


# test cases
add_executable(Parseavi Parseavi.cpp)
# link opencv libs
target_link_libraries(Parseavi ${OpenCV_LIBS})


add_executable(OpenCamera OpenCamera.cpp)
target_link_libraries(OpenCamera ${OpenCV_LIBS})

add_executable(ParsecameraWriteToAVI ParsecameraWriteToAVI.cpp)
target_link_libraries(ParsecameraWriteToAVI ${OpenCV_LIBS})

add_executable(writeavi WriteAvi.cpp)
target_link_libraries(writeavi ${OpenCV_LIBS})

add_executable(cutavi CutAVI.cpp)
target_link_libraries(cutavi ${OpenCV_LIBS})

add_executable(ParsecameraTakeAScreenShot ParsecameraTakeAScreenShot.cpp)
target_link_libraries(ParsecameraTakeAScreenShot ${OpenCV_LIBS})

