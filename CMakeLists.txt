cmake_minimum_required(VERSION 3.14)
project(pybg LANGUAGES CXX)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost.Geometry
find_package(Boost REQUIRED)

find_package(
  Python
  COMPONENTS Interpreter Development.Module
  REQUIRED)

# Add nanobind
add_subdirectory(external/nanobind)

# Include directories
include_directories(${Boost_INCLUDE_DIRS}
                    ${CMAKE_CURRENT_SOURCE_DIR}/cxx/include)

# Create the Python module
nanobind_add_module(_cartesian cxx/pybind/cartesian.cpp)
target_link_libraries(_cartesian)
nanobind_add_module(_geographic cxx/pybind/geographic.cpp)
target_link_libraries(_geographic)
nanobind_add_module(_wkt cxx/pybind/wkt.cpp)
target_link_libraries(_wkt)
