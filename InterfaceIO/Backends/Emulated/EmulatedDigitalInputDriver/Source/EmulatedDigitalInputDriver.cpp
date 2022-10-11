#include "EmulatedDigitalInputDriver.h"
#include "AsyncClassCallback.h"

namespace InterfaceIO
{
	namespace Backends
	{
		namespace Emulated
		{
			EmulatedDigitalInputDriver::EmulatedDigitalInputDriver(Core::ITaskQueueSPtr pTaskQueue)
				: Devices::BaseDigitalInputDriver(pTaskQueue)
			{
			}

			EmulatedDigitalInputDriver::~EmulatedDigitalInputDriver()
			{
			}

			void EmulatedDigitalInputDriver::Initialise()
			{
				// do nothing
				ExecuteCallback(m_pDefaultCallback);
			}

			void EmulatedDigitalInputDriver::Shutdown()
			{
				// do nothing
				ExecuteCallback(m_pDefaultCallback);
			}

			void EmulatedDigitalInputDriver::GetState()
			{
				ExecuteCallback(m_pGetStateCallback, m_state);
			}

			void EmulatedDigitalInputDriver::BeginSetState(bool state, VoidCallbackSPtr pCallback)
			{
				AssignCallback(pCallback, m_pDefaultCallback);
				Core::AsyncClassCallback<EmulatedDigitalInputDriver, bool>(m_pTaskQueue, this, &EmulatedDigitalInputDriver::SetState).BeginInvoke(state);
			}

			void EmulatedDigitalInputDriver::SetState(bool state)
			{
				m_state = state;
				ExecuteCallback(m_pDefaultCallback);
			}
		}
	}
}
