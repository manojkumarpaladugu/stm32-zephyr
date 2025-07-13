/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
 */

// ----------------------------------------------------------------------------
// Header includes
// ----------------------------------------------------------------------------

#include "Logging.h"
#include "Assert.h"
#include "LogCore.hpp"
#include "LogToStdOut.hpp"

// ----------------------------------------------------------------------------
// Private functions
// ----------------------------------------------------------------------------

static void InitializeLogging(void)
{
    // Register the consumer
    static LogToStdOut logToStdOut;
    LogCore::RegisterConsumer(cLogToStdOutId, logToStdOut);

    // Initialize the log queue if asynchronous logging is enabled
#ifdef CONFIG_LIB_COMMONS_LOGGING_ASYNC
    static uint8_t logBuffer[1024];
    LogCore::InitializeQueue(logBuffer, sizeof(logBuffer));

    // Start the log core to process the queue
    LogCore::Start();
#endif
}

// ----------------------------------------------------------------------------
// Main function
// ----------------------------------------------------------------------------

int main(void)
{
    InitializeLogging();

    LOG_DEBUG("This is a debug message");
    LOG_INFO("This is an info message");
    LOG_WARN("This is a warning message");
    LOG_ERROR("This is an error message");
    LOG_CRITICAL("This is a critical message");

    ASSERT(false);

    return 0;
}
