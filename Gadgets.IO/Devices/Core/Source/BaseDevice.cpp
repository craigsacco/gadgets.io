#include "AsyncClassCallback.h"
#include "BaseDevice.h"
#include "IDriver.h"
#include "ITaskQueue.h"

namespace GadgetsIO
{
	namespace Devices
	{
		BaseDevice::BaseDevice(IDriverSPtr pDriver, Core::ITaskQueueSPtr pTaskQueue)
			: m_pDriver(pDriver)
			, m_pTaskQueue(pTaskQueue)
		{
		}

		BaseDevice::~BaseDevice()
		{
		}

		void BaseDevice::Wait()
		{
		}

		void BaseDevice::Initialise()
		{
			BeginAsyncOperation();

			const auto pCallback = std::make_shared<Core::AsyncClassCallback<BaseDevice>>(
				GetCallbackDispatcher(), this, &BaseDevice::InitialiseCallback);
			m_pDriver->BeginInitialise(pCallback);
		}

		void BaseDevice::InitialiseCallback()
		{
			FinishAsyncOperation();
		}

		void BaseDevice::Shutdown()
		{
			BeginAsyncOperation();

			const auto pCallback = std::make_shared<Core::AsyncClassCallback<BaseDevice>>(
				GetCallbackDispatcher(), this, &BaseDevice::ShutdownCallback);
			m_pDriver->BeginShutdown(pCallback);
		}

		void BaseDevice::ShutdownCallback()
		{
			FinishAsyncOperation();
		}

		Core::ITaskQueueSPtr BaseDevice::GetCallbackDispatcher() const
		{
			return m_pTaskQueue;
		}
	}
}
