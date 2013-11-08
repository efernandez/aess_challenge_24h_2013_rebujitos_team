set(CMAKE_TOOLCHAIN_FILE /usr/share/arduino/cmake/ArduinoToolchain.cmake)

cmake_minimum_required(VERSION 2.8)

project(keyboard C CXX)

generate_arduino_example(keyboard
    LIBRARY .
    EXAMPLE keyboard
    BOARD uno
    PORT /dev/ttyACM0)

