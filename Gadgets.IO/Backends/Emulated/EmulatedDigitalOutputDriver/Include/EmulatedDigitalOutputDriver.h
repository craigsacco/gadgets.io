#pragma once

#include "BaseDigitalOutputDriver.h"
#include "IDigitalOutputDriver.h"

namespace GadgetsIO {
namespace Backends {
namespace Emulated {
class EmulatedDigitalOutputDriver : public Devices::BaseDigitalOutputDriver {
  public:
    explicit EmulatedDigitalOutputDriver( Core::ITaskQueueSPtr pTaskQueue );
    ~EmulatedDigitalOutputDriver();

  private:
    // overrides from BaseDriver
    void Initialise() override;
    void Shutdown() override;

    // overrides from BaseDigitalOutputDriver
    void On() override;
    void Off() override;
    void Toggle() override;
    void GetState() override;

  private:
    bool m_state = false;
};
} // namespace Emulated
} // namespace Backends
} // namespace GadgetsIO
