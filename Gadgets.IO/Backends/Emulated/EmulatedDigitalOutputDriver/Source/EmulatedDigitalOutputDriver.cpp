#include "EmulatedDigitalOutputDriver.h"
#include "AsyncClassCallback.h"

namespace GadgetsIO {
namespace Backends {
namespace Emulated {
EmulatedDigitalOutputDriver::EmulatedDigitalOutputDriver(
    Core::ITaskQueueSPtr pTaskQueue )
    : Devices::BaseDigitalOutputDriver( pTaskQueue )
{
}

EmulatedDigitalOutputDriver::~EmulatedDigitalOutputDriver()
{
}

void EmulatedDigitalOutputDriver::Initialise()
{
    Off();
}

void EmulatedDigitalOutputDriver::Shutdown()
{
    Off();
}

void EmulatedDigitalOutputDriver::On()
{
    m_state = true;
    ExecuteCallback( m_pDefaultCallback );
}

void EmulatedDigitalOutputDriver::Off()
{
    m_state = false;
    ExecuteCallback( m_pDefaultCallback );
}

void EmulatedDigitalOutputDriver::Toggle()
{
    m_state = !m_state;
    ExecuteCallback( m_pDefaultCallback );
}

void EmulatedDigitalOutputDriver::GetState()
{
    ExecuteCallback( m_pGetStateCallback, m_state );
}
} // namespace Emulated
} // namespace Backends
} // namespace GadgetsIO
