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

#include "EmulatedDigitalInputDriver.h"
#include "AsyncClassCallback.h"

namespace GadgetsIO {
namespace Backends {
namespace Emulated {
EmulatedDigitalInputDriver::EmulatedDigitalInputDriver(
    Core::ITaskQueueSPtr pTaskQueue )
    : Devices::BaseDigitalInputDriver( pTaskQueue )
{
}

EmulatedDigitalInputDriver::~EmulatedDigitalInputDriver()
{
}

void EmulatedDigitalInputDriver::Initialise()
{
    // do nothing
    ExecuteCallback( m_pDefaultCallback );
}

void EmulatedDigitalInputDriver::Shutdown()
{
    // do nothing
    ExecuteCallback( m_pDefaultCallback );
}

void EmulatedDigitalInputDriver::GetState()
{
    ExecuteCallback( m_pGetStateCallback, m_state );
}

void EmulatedDigitalInputDriver::BeginSetState( bool state,
                                                VoidCallbackSPtr pCallback )
{
    AssignCallback( pCallback, m_pDefaultCallback );
    Core::AsyncClassCallback<EmulatedDigitalInputDriver, bool>(
        m_pTaskQueue, this, &EmulatedDigitalInputDriver::SetState )
        .BeginInvoke( state );
}

void EmulatedDigitalInputDriver::SetState( bool state )
{
    m_state = state;
    ExecuteCallback( m_pDefaultCallback );
}
} // namespace Emulated
} // namespace Backends
} // namespace GadgetsIO
