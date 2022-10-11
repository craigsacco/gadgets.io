#pragma once

#include "IDevice.h"

namespace GadgetsIO {
namespace Devices {
class IDigitalInput : public virtual IDevice {
  public:
    virtual bool GetState() = 0;
};
} // namespace Devices
} // namespace GadgetsIO
