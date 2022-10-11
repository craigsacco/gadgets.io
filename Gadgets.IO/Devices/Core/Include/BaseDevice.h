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

#include "IDevice.h"

#include <memory>

namespace GadgetsIO {
namespace Core {
class ITaskQueue;
using ITaskQueueSPtr = std::shared_ptr<ITaskQueue>;
} // namespace Core

namespace Devices {
class IDriver;
using IDriverSPtr = std::shared_ptr<IDriver>;

class BaseDevice : public virtual IDevice {
  public:
    BaseDevice( IDriverSPtr pDriver, Core::ITaskQueueSPtr pTaskQueue );
    virtual ~BaseDevice();

    // overrides from IDevice
    void Initialise() override;
    void Shutdown() override;
    void Wait() override;

  protected:
    void InitialiseCallback();
    void ShutdownCallback();

    Core::ITaskQueueSPtr GetCallbackDispatcher() const;
    void BeginAsyncOperation();
    void FinishAsyncOperation();

  private:
    IDriverSPtr m_pDriver;
    Core::ITaskQueueSPtr m_pTaskQueue;
};
} // namespace Devices
} // namespace GadgetsIO
