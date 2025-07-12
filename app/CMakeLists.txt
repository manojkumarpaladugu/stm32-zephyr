#
# SPDX-License-Identifier: Apache-2.0
#
# Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
#

cmake_minimum_required(VERSION 4.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../third-party)

list(APPEND ZEPHYR_EXTRA_MODULES "${CMAKE_CURRENT_SOURCE_DIR}/../../modules/lib/Commons")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(STM32-NUCLEO LANGUAGES C CXX VERSION 1.0.0)

# Zephyr creates app target automatically
set(APPLICATION_NAME app)

target_compile_definitions(${APPLICATION_NAME}
    PUBLIC
        LOG_MODULE_NAME="app"
        MODULE_LOG_LEVEL=LOG_LEVEL_DEBUG
)

add_subdirectory(Logging)

target_sources(${APPLICATION_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
)

# zephyr_interface is a source-less library that encapsulates all the global compiler options
# and flags necessary for building code within the Zephyr environment. ALl libraries should link it.
target_link_libraries(Commons PUBLIC zephyr_interface)
zephyr_link_libraries(Commons)

target_link_libraries(${APPLICATION_NAME} PRIVATE Commons)
