/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
 */

// ----------------------------------------------------------------------------
// Header includes
// ----------------------------------------------------------------------------

#include "Assert.h"
#include "LogToStdOut.hpp"

#include <zephyr/sys/printk.h>

// ----------------------------------------------------------------------------
// Public functions
// ----------------------------------------------------------------------------

void LogToStdOut::ProcessLogMessage(const uint8_t* message, size_t length)
{
    ASSERT(message != nullptr);
    ASSERT(length > 0);

    printk("%.*s\n", (int)length, message);
}
