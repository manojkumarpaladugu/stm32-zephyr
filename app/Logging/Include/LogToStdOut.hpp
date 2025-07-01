/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
 */

#pragma once

// ----------------------------------------------------------------------------
// Header includes
// ----------------------------------------------------------------------------

#include "IConsumer.hpp"

// ----------------------------------------------------------------------------
// Class definition
// ----------------------------------------------------------------------------

class LogToStdOut : public IConsumer
{
public:

    /**
     * @brief Process a log message and output it to standard output.
     *
     * @param[in] message Pointer to the log message.
     * @param[in] length Length of the log message.
     * @param[in] level Log level of the message.
     */
    void ProcessLog(const uint8_t* message, size_t length, int level) override;
};
