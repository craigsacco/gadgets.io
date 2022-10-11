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
