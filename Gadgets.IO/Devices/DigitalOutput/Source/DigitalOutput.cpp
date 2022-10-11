/*
 * Copyright (C) 2022 Craig Sacco
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "DigitalOutput.h"
#include "AsyncClassCallback.h"
#include "IDigitalOutputDriver.h"

namespace GadgetsIO {
namespace Devices {
DigitalOutput::DigitalOutput( IDigitalOutputDriverSPtr pDriver,
                              Core::ITaskQueueSPtr pTaskQueue )
    : BaseDevice( pDriver, pTaskQueue )
    , m_pDigitalOutputDriver( pDriver )
{
}

DigitalOutput::~DigitalOutput()
{
}

void DigitalOutput::On()
{
    BeginAsyncOperation();

    const auto pCallback =
        std::make_shared<Core::AsyncClassCallback<DigitalOutput>>(
            GetCallbackDispatcher(), this, &DigitalOutput::DefaultCallback );
    m_pDigitalOutputDriver->BeginOn( pCallback );
}

void DigitalOutput::Off()
{
    BeginAsyncOperation();

    const auto pCallback =
        std::make_shared<Core::AsyncClassCallback<DigitalOutput>>(
            GetCallbackDispatcher(), this, &DigitalOutput::DefaultCallback );
    m_pDigitalOutputDriver->BeginOff( pCallback );
}

void DigitalOutput::Toggle()
{
    BeginAsyncOperation();

    const auto pCallback =
        std::make_shared<Core::AsyncClassCallback<DigitalOutput>>(
            GetCallbackDispatcher(), this, &DigitalOutput::DefaultCallback );
    m_pDigitalOutputDriver->BeginToggle( pCallback );
}

void DigitalOutput::DefaultCallback()
{
    FinishAsyncOperation();
}

bool DigitalOutput::GetState()
{
    BeginAsyncOperation();

    const auto pCallback =
        std::make_shared<Core::AsyncClassCallback<DigitalOutput, bool>>(
            GetCallbackDispatcher(), this, &DigitalOutput::GetStateCallback );
    m_pDigitalOutputDriver->BeginGetState( pCallback );

    Wait();
    return m_state;
}

void DigitalOutput::GetStateCallback( bool state )
{
    m_state = state;

    FinishAsyncOperation();
}
} // namespace Devices
} // namespace GadgetsIO
