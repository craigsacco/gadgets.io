#include "DigitalInput.h"
#include "AsyncClassCallback.h"
#include "IDigitalInputDriver.h"

namespace GadgetsIO {
namespace Devices {
DigitalInput::DigitalInput( IDigitalInputDriverSPtr pDriver,
                            Core::ITaskQueueSPtr pTaskQueue )
    : BaseDevice( pDriver, pTaskQueue )
    , m_pDigitalInputDriver( pDriver )
{
}

DigitalInput::~DigitalInput()
{
}

bool DigitalInput::GetState()
{
    BeginAsyncOperation();

    const auto pCallback =
        std::make_shared<Core::AsyncClassCallback<DigitalInput, bool>>(
            GetCallbackDispatcher(), this, &DigitalInput::GetStateCallback );
    m_pDigitalInputDriver->BeginGetState( pCallback );

    Wait();
    return m_state;
}

void DigitalInput::GetStateCallback( bool state )
{
    m_state = state;

    FinishAsyncOperation();
}
} // namespace Devices
} // namespace GadgetsIO
