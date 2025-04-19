#
# SPDX-License-Identifier: Apache-2.0
#

cmake_minimum_required(VERSION 4.0.0)

find_package(Zephyr HINTS $ENV{ZEPHYR_BASE} REQUIRED)

list(APPEND ZEPHYR_EXTRA_MODULES
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/commons/
)

project(ZEPHYR-STM32-NUCLEO LANGUAGES C VERSION 1.0.0)

# Zephyr creates app target automatically
set(APPLICATION_NAME app)
target_sources(${APPLICATION_NAME} PRIVATE src/main.c)

message(STATUS "app - pw_log_BACKEND is set to ${pw_log_BACKEND}")
message(STATUS "app - pw_log_string.handler_BACKEND is set to ${pw_log_string.handler_BACKEND}")

target_link_libraries(${APPLICATION_NAME} PUBLIC
  CommonsLogging
)
