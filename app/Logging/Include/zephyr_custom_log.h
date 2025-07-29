/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
 */

#pragma once

#define MODULE_NAME "Zephyr"

#include <zephyr/logging/log_core.h>
#include <zephyr/sys/__assert.h>

#include "Logging.h"

#undef LOG_DBG
#undef LOG_INF
#undef LOG_WRN
#undef LOG_ERR

#define Z_COMMONS_LOG(_level, customLogMacro, fmt, ...) \
    do {                                                \
        if (!Z_LOG_CONST_LEVEL_CHECK(_level)) {         \
            break;                                      \
        }                                               \
        customLogMacro(fmt, ##__VA_ARGS__);             \
    } while(false)

#define LOG_DBG(fmt, ...) \
    Z_COMMONS_LOG(LOG_LEVEL_DBG, LOG_DEBUG, fmt, ##__VA_ARGS__)

#define LOG_INF(fmt, ...) \
    Z_COMMONS_LOG(LOG_LEVEL_INF, LOG_INFO, fmt, ##__VA_ARGS__)

#define LOG_WRN(fmt, ...) \
    Z_COMMONS_LOG(LOG_LEVEL_WRN, LOG_WARN, fmt, ##__VA_ARGS__)

#define LOG_ERR(fmt, ...) \
    Z_COMMONS_LOG(LOG_LEVEL_ERR, LOG_ERROR, fmt, ##__VA_ARGS__)
