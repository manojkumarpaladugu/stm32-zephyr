/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
 */

// ----------------------------------------------------------------------------
// Header includes
// ----------------------------------------------------------------------------

#define LOG_MODULE_NAME "main"
#define MODULE_LOG_LEVEL LOG_LEVEL_DEBUG

// Must be included after the log level and module name definitions
#include "Logging.h"

#ifdef CONFIG_LIB_COMMONS_LOGGING_ASYNC
    #include "LogQueue.hpp"
#endif
#include "LogDispatcher.hpp"
#include "LogToStdOut.hpp"

// ----------------------------------------------------------------------------
// Private functions
// ----------------------------------------------------------------------------

static void InitializeLogging(void)
{
    // Register the consumer
    static LogToStdOut logToStdOut;
    LogDispatcher::RegisterConsumer(logToStdOut);

    // Initialize the log queue if asynchronous logging is enabled
#ifdef CONFIG_LIB_COMMONS_LOGGING_ASYNC
    uint8_t logBuffer[1024];
    LogQueue::Initialize(logBuffer, sizeof(logBuffer));

    LogDispatcher::Start();
#endif
}

// ----------------------------------------------------------------------------
// Main function
// ----------------------------------------------------------------------------

int main(void)
{
    InitializeLogging();

    LOG_DEBUG("Hello world!");
    LOG_INFO("My name is %s", "Manoj Kumar Paladugu");

    return 0;
}
