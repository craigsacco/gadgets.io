#include "BaseDigitalInputDriver.h"
#include "AsyncClassCallback.h"

namespace GadgetsIO {
namespace Devices {
BaseDigitalInputDriver::BaseDigitalInputDriver(
    Core::ITaskQueueSPtr pTaskQueue )
    : BaseDriver( pTaskQueue )
{
}

BaseDigitalInputDriver::~BaseDigitalInputDriver()
{
}

void BaseDigitalInputDriver::BeginGetState( StateCallbackSPtr pCallback )
{
    AssignCallback( pCallback, m_pGetStateCallback );
    Core::AsyncClassCallback<BaseDigitalInputDriver>(
        m_pTaskQueue, this, &BaseDigitalInputDriver::GetState )
        .BeginInvoke();
}
} // namespace Devices
} // namespace GadgetsIO
