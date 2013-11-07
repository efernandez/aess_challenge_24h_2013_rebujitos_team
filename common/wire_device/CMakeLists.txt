set(CMAKE_TOOLCHAIN_FILE /usr/share/arduino/cmake/ArduinoToolchain.cmake)

cmake_minimum_required(VERSION 2.8)

project(wire_device C CXX)

link_directories(${CMAKE_SOURCE_DIR}/..)

generate_arduino_example(example_master_writer
    LIBRARY wire_device
    EXAMPLE master_writer
    BOARD mega2560
    PORT /dev/ttyACM0)

