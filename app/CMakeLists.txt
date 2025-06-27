#
# SPDX-License-Identifier: Apache-2.0
#

cmake_minimum_required(VERSION 4.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(STM32-NUCLEO LANGUAGES C CXX VERSION 1.0.0)

# Zephyr creates app target automatically
set(APPLICATION_NAME app)
target_sources(${APPLICATION_NAME} PRIVATE Source/Main.cpp)

target_link_libraries(${APPLICATION_NAME} PRIVATE Commons)
