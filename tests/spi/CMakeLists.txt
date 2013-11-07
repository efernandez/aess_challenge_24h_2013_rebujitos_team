set(CMAKE_TOOLCHAIN_FILE /usr/share/arduino/cmake/ArduinoToolchain.cmake)

cmake_minimum_required(VERSION 2.8)

project(spi C CXX)

generate_arduino_example(echo
    LIBRARY .
    EXAMPLE echo
    BOARD mega2560
    PORT /dev/ttyACM0)

