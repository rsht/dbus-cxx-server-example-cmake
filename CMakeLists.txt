project(dbus-cxx-test)
cmake_minimum_required(VERSION 2.8.12)

add_compile_options(-std=c++11)

LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules")

find_package(dbus-cxx REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

include_directories( ${DBUS-CXX_INCLUDE_DIRS} )
target_link_libraries(${PROJECT_NAME} ${DBUS-CXX_LIBRARIES})
