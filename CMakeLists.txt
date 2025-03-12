cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(evt_test)

file(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})

include_directories(drivers/t5838)
add_subdirectory(drivers)

list(APPEND ZEPHYR_EXTRA_MODULES
  ${CMAKE_CURRENT_SOURCE_DIR}/drivers/t5838
)