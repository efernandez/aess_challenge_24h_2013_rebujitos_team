set(CMAKE_TOOLCHAIN_FILE /usr/share/arduino/cmake/ArduinoToolchain.cmake)

cmake_minimum_required(VERSION 2.8)

project(serial C CXX)

generate_arduino_example(echo
    LIBRARY .
    EXAMPLE echo
    BOARD mega2560
    PORT /dev/ttyACM0)

generate_arduino_example(sentence
    LIBRARY .
    EXAMPLE sentence
    BOARD mega2560
    PORT /dev/ttyACM0)

