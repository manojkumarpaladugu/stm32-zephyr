/*
 * SPDX-License-Identifier: Apache-2.0
 */

 #include "logging.h"

 #define PW_LOG_MODULE_NAME "main"

int main(void)
{
    PW_LOG_INFO("Hello World!\n");
    PW_LOG_INFO("Welcome %s\n", "Manoj");
    return 0;
}
