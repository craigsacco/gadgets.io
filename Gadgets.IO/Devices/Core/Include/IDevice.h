#pragma once

namespace GadgetsIO {
namespace Devices {
class IDevice {
  public:
    virtual void Initialise() = 0;
    virtual void Shutdown() = 0;

    virtual void Wait() = 0;
};
} // namespace Devices
} // namespace GadgetsIO