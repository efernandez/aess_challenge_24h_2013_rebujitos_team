set(CMAKE_TOOLCHAIN_FILE /usr/share/arduino/cmake/ArduinoToolchain.cmake)

cmake_minimum_required(VERSION 2.8)

project(hardware_serial C CXX)

generate_arduino_example(echo_0
    LIBRARY .
    EXAMPLE echo
    BOARD mega2560
    PORT /dev/ttyACM0)

generate_arduino_example(echo_1
    LIBRARY .
    EXAMPLE echo
    BOARD mega2560
    PORT /dev/ttyACM1)

