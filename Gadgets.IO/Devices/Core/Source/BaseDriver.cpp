#include "BaseDriver.h"
#include "AsyncClassCallback.h"
#include "ITaskQueue.h"

namespace GadgetsIO
{
	namespace Devices
	{
		BaseDriver::BaseDriver(Core::ITaskQueueSPtr pTaskQueue)
			: m_pTaskQueue(pTaskQueue)
		{
		}

		BaseDriver::~BaseDriver()
		{
		}

		void BaseDriver::BeginInitialise(VoidCallbackSPtr pCallback)
		{
			AssignCallback(pCallback, m_pDefaultCallback);
			Core::AsyncClassCallback<BaseDriver>(m_pTaskQueue, this, &BaseDriver::Initialise).BeginInvoke();
		}

		void BaseDriver::BeginShutdown(VoidCallbackSPtr pCallback)
		{
			AssignCallback(pCallback, m_pDefaultCallback);
			Core::AsyncClassCallback<BaseDriver>(m_pTaskQueue, this, &BaseDriver::Shutdown).BeginInvoke();
		}
	}
}
