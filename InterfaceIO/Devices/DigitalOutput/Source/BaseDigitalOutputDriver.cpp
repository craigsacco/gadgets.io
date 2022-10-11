#include "BaseDigitalOutputDriver.h"
#include "AsyncClassCallback.h"

namespace InterfaceIO
{
	namespace Devices
	{
		BaseDigitalOutputDriver::BaseDigitalOutputDriver(Core::ITaskQueueSPtr pTaskQueue)
			: BaseDriver(pTaskQueue)
		{
		}

		BaseDigitalOutputDriver::~BaseDigitalOutputDriver()
		{
		}

		void BaseDigitalOutputDriver::BeginOn(VoidCallbackSPtr pCallback)
		{
			AssignCallback(pCallback, m_pDefaultCallback);
			Core::AsyncClassCallback<BaseDigitalOutputDriver>(m_pTaskQueue, this, &BaseDigitalOutputDriver::On).BeginInvoke();
		}

		void BaseDigitalOutputDriver::BeginOff(VoidCallbackSPtr pCallback)
		{
			AssignCallback(pCallback, m_pDefaultCallback);
			Core::AsyncClassCallback<BaseDigitalOutputDriver>(m_pTaskQueue, this, &BaseDigitalOutputDriver::Off).BeginInvoke();
		}

		void BaseDigitalOutputDriver::BeginToggle(VoidCallbackSPtr pCallback)
		{
			AssignCallback(pCallback, m_pDefaultCallback);
			Core::AsyncClassCallback<BaseDigitalOutputDriver>(m_pTaskQueue, this, &BaseDigitalOutputDriver::Toggle).BeginInvoke();
		}

		void BaseDigitalOutputDriver::BeginGetState(StateCallbackSPtr pCallback)
		{
			AssignCallback(pCallback, m_pGetStateCallback);
			Core::AsyncClassCallback<BaseDigitalOutputDriver>(m_pTaskQueue, this, &BaseDigitalOutputDriver::GetState).BeginInvoke();
		}
	}
}
