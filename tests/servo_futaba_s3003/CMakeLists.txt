set(CMAKE_TOOLCHAIN_FILE /usr/share/arduino/cmake/ArduinoToolchain.cmake)

cmake_minimum_required(VERSION 2.8)

project(servo_futaba_s3003 C CXX)

generate_arduino_example(example_sweep
    LIBRARY .
    EXAMPLE sweep
    BOARD mega2560
    PORT /dev/ttyACM0)

