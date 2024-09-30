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
file(GLOB_RECURSE PYBIND_SOURCES "cxx/pybind/*.cpp")
nanobind_add_module(_core ${PYBIND_SOURCES})
