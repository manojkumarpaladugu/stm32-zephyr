#
# SPDX-License-Identifier: Apache-2.0
#

cmake_minimum_required(VERSION 4.0.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(ZEPHYR-STM32-NUCLEO LANGUAGES C VERSION 1.0.0)

# Zephyr creates app target automatically
set(APPLICATION_NAME app)
target_sources(${APPLICATION_NAME} PRIVATE src/main.c)

target_link_libraries(${APPLICATION_NAME}
    PRIVATE commons
)
