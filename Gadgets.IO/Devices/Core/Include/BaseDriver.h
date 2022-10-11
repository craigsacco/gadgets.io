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

#include "IDriver.h"

#include <memory>

namespace GadgetsIO {
namespace Core {
class ITaskQueue;
using ITaskQueueSPtr = std::shared_ptr<ITaskQueue>;
} // namespace Core

namespace Devices {
class BaseDriver : public virtual IDriver {
  public:
    explicit BaseDriver( Core::ITaskQueueSPtr pTaskQueue );
    ~BaseDriver();

    // overrides from IDriver
    void BeginInitialise( VoidCallbackSPtr pCallback ) override;
    void BeginShutdown( VoidCallbackSPtr pCallback ) override;

  protected:
    virtual void Initialise() = 0;
    virtual void Shutdown() = 0;

    template <typename... Args>
    void
    AssignCallback( std::shared_ptr<Core::IAsyncCallback<Args...>> pCallback,
                    std::shared_ptr<Core::IAsyncCallback<Args...>> &pTarget )
    {
        pTarget = pCallback;
    }

    template <>
    void AssignCallback( std::shared_ptr<Core::IAsyncCallback<>> pCallback,
                         std::shared_ptr<Core::IAsyncCallback<>> &pTarget )
    {
        pTarget = pCallback;
    }

    template <typename... Args>
    void
    ExecuteCallback( std::shared_ptr<Core::IAsyncCallback<Args...>> &pTarget,
                     Args... args )
    {
        pTarget->BeginInvoke( args... );
        pTarget = nullptr;
    }

    template <>
    void ExecuteCallback( std::shared_ptr<Core::IAsyncCallback<>> &pTarget )
    {
        pTarget->BeginInvoke();
        pTarget = nullptr;
    }

  protected:
    Core::ITaskQueueSPtr m_pTaskQueue;
    VoidCallbackSPtr m_pDefaultCallback = nullptr;
};
} // namespace Devices
} // namespace GadgetsIO
