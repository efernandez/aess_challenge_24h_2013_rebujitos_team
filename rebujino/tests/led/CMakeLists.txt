set(CMAKE_TOOLCHAIN_FILE /usr/share/arduino/cmake/ArduinoToolchain.cmake)

cmake_minimum_required(VERSION 2.8)

project(led C CXX)

generate_arduino_example(led
    LIBRARY .
    EXAMPLE led
    BOARD uno
    PORT /dev/ttyACM0)

