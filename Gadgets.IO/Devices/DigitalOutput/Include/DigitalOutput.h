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

#pragma once

#include "BaseDevice.h"
#include "IDigitalOutput.h"

namespace GadgetsIO {
namespace Devices {
class IDigitalOutputDriver;
using IDigitalOutputDriverSPtr = std::shared_ptr<IDigitalOutputDriver>;

class DigitalOutput : public BaseDevice, public virtual IDigitalOutput {
  public:
    DigitalOutput( IDigitalOutputDriverSPtr pDriver,
                   Core::ITaskQueueSPtr pTaskQueue );
    virtual ~DigitalOutput();

    // overrides from IDigitalOutput
    void On() override;
    void Off() override;
    void Toggle() override;
    bool GetState() override;

  protected:
    void DefaultCallback();
    void GetStateCallback( bool state );

  private:
    IDigitalOutputDriverSPtr m_pDigitalOutputDriver;
    bool m_state;
};
} // namespace Devices
} // namespace GadgetsIO
