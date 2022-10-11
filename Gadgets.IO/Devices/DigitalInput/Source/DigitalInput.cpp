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

#include "DigitalInput.h"
#include "AsyncClassCallback.h"
#include "IDigitalInputDriver.h"

namespace GadgetsIO {
namespace Devices {
DigitalInput::DigitalInput( IDigitalInputDriverSPtr pDriver,
                            Core::ITaskQueueSPtr pTaskQueue )
    : BaseDevice( pDriver, pTaskQueue )
    , m_pDigitalInputDriver( pDriver )
{
}

DigitalInput::~DigitalInput()
{
}

bool DigitalInput::GetState()
{
    BeginAsyncOperation();

    const auto pCallback =
        std::make_shared<Core::AsyncClassCallback<DigitalInput, bool>>(
            GetCallbackDispatcher(), this, &DigitalInput::GetStateCallback );
    m_pDigitalInputDriver->BeginGetState( pCallback );

    Wait();
    return m_state;
}

void DigitalInput::GetStateCallback( bool state )
{
    m_state = state;

    FinishAsyncOperation();
}
} // namespace Devices
} // namespace GadgetsIO
