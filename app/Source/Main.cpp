/*
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_MODULE_NAME "main"
#define MODULE_LOG_LEVEL LOG_LEVEL_DEBUG

// Must be included after the log level and module name definitions
#include "Logging.h"

int main(void)
{
    LOG_DEBUG("Hi");
    LOG_INFO("Hello world!");

    return 0;
}
