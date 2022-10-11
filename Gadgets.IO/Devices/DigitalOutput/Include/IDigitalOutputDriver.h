#pragma once

#include "IDriver.h"

namespace GadgetsIO {
namespace Devices {
class IDigitalOutputDriver : public virtual IDriver {
  public:
    using StateCallbackSPtr = std::shared_ptr<Core::IAsyncCallback<bool>>;

    virtual void BeginOn( VoidCallbackSPtr pCallback ) = 0;
    virtual void BeginOff( VoidCallbackSPtr pCallback ) = 0;
    virtual void BeginToggle( VoidCallbackSPtr pCallback ) = 0;
    virtual void BeginGetState( StateCallbackSPtr pCallback ) = 0;
};
} // namespace Devices
} // namespace GadgetsIO
