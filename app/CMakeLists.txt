cmake_minimum_required(VERSION 4.0.0)

find_package(Zephyr HINTS $ENV{ZEPHYR_BASE} REQUIRED)

project(ZEPHYR-STM32-NUCLEO LANGUAGES C)

# Zephyr creates app target automatically
set(APPLICATION_NAME app)
target_sources(${APPLICATION_NAME} PRIVATE src/main.c)
