cmake_minimum_required(VERSION 3.31)
project(dem_2d)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(dem_2d ${SOURCES})

# Eigen3 is header only and required for callers
find_package(Eigen3 REQUIRED)
target_include_directories( ${PROJECT_NAME} SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIR} )
# Disable Eigen's built in multithreading as we will use OpenMP around Eigen
target_compile_definitions( ${PROJECT_NAME} PUBLIC EIGEN_DONT_PARALLELIZE )
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    # EIGEN_DONT_ALIGN also enables EIGEN_DONT_VECTORIZE
    target_compile_definitions( ${PROJECT_NAME} PUBLIC EIGEN_DONT_ALIGN EIGEN_INITIALIZE_MATRICES_BY_NAN )
endif()
target_link_libraries( ${PROJECT_NAME} Eigen3::Eigen )

# HDF5
find_package( HDF5 REQUIRED )
if( NOT ${HDF5_FOUND} )
    message( FATAL_ERROR "HDF5 not found." )
endif()
target_include_directories( ${PROJECT_NAME} SYSTEM PUBLIC ${HDF5_INCLUDE_DIRS} )
target_compile_definitions( ${PROJECT_NAME} PUBLIC USE_HDF5 )
target_link_libraries( ${PROJECT_NAME} ${HDF5_LIBRARIES} )

# OpenGL
find_package( OpenGL REQUIRED )

# GLUT
find_package( GLUT REQUIRED )