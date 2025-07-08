cmake_minimum_required(VERSION 3.31)
project(dem_2d)

set(CMAKE_CXX_STANDARD 20)

# Find all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add the src directory to the include path
target_include_directories(${PROJECT_NAME} PUBLIC src)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# --- Find and Link Packages ---

# Eigen3
find_package(Eigen3 REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${EIGEN3_INCLUDE_DIR})
target_compile_definitions(${PROJECT_NAME} PUBLIC EIGEN_DONT_PARALLELIZE)

# HDF5
find_package(HDF5 REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${HDF5_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${HDF5_LIBRARIES})

# OpenGL and GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})