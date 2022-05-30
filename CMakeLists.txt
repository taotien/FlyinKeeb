cmake_minimum_required(VERSION 3.13)

find_package(pico-sdk CONFIG)
find_package(tinyusb CONFIG)
# set(PICO_SDK_FETCH_FROM_GIT on)
# include(pico_sdk_import.cmake)

project(FlyinKeeb)

set(PICO_BOARD adafruit_feather_rp2040)

pico_sdk_init()

add_subdirectory(src/c)
add_subdirectory(lib/c)
