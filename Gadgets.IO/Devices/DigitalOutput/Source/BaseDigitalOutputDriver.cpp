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

#include "BaseDigitalOutputDriver.h"
#include "AsyncClassCallback.h"

namespace GadgetsIO {
namespace Devices {
BaseDigitalOutputDriver::BaseDigitalOutputDriver(
    Core::ITaskQueueSPtr pTaskQueue )
    : BaseDriver( pTaskQueue )
{
}

BaseDigitalOutputDriver::~BaseDigitalOutputDriver()
{
}

void BaseDigitalOutputDriver::BeginOn( VoidCallbackSPtr pCallback )
{
    AssignCallback( pCallback, m_pDefaultCallback );
    Core::AsyncClassCallback<BaseDigitalOutputDriver>(
        m_pTaskQueue, this, &BaseDigitalOutputDriver::On )
        .BeginInvoke();
}

void BaseDigitalOutputDriver::BeginOff( VoidCallbackSPtr pCallback )
{
    AssignCallback( pCallback, m_pDefaultCallback );
    Core::AsyncClassCallback<BaseDigitalOutputDriver>(
        m_pTaskQueue, this, &BaseDigitalOutputDriver::Off )
        .BeginInvoke();
}

void BaseDigitalOutputDriver::BeginToggle( VoidCallbackSPtr pCallback )
{
    AssignCallback( pCallback, m_pDefaultCallback );
    Core::AsyncClassCallback<BaseDigitalOutputDriver>(
        m_pTaskQueue, this, &BaseDigitalOutputDriver::Toggle )
        .BeginInvoke();
}

void BaseDigitalOutputDriver::BeginGetState( StateCallbackSPtr pCallback )
{
    AssignCallback( pCallback, m_pGetStateCallback );
    Core::AsyncClassCallback<BaseDigitalOutputDriver>(
        m_pTaskQueue, this, &BaseDigitalOutputDriver::GetState )
        .BeginInvoke();
}
} // namespace Devices
} // namespace GadgetsIO
