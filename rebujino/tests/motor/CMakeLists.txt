set(CMAKE_TOOLCHAIN_FILE /usr/share/arduino/cmake/ArduinoToolchain.cmake)

cmake_minimum_required(VERSION 2.8)

project(motor C CXX)

generate_arduino_example(motor
    LIBRARY .
    EXAMPLE motor
    BOARD uno
    PORT /dev/ttyACM0)

