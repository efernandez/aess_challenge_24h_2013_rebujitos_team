set(CMAKE_TOOLCHAIN_FILE /usr/share/arduino/cmake/ArduinoToolchain.cmake)

cmake_minimum_required(VERSION 2.8)

project(ps2_keyboard C CXX)

link_directories(~/sketchbook/libraries)

generate_arduino_example(ps2_keyboard_test
    LIBRARY .
    EXAMPLE ps2_keyboard_test
    BOARD mega2560
    PORT /dev/ttyACM0)

