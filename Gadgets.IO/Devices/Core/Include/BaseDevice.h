#pragma once

#include "IDevice.h"

#include <memory>

namespace GadgetsIO
{
	namespace Core
	{
		class ITaskQueue;
		using ITaskQueueSPtr = std::shared_ptr<ITaskQueue>;
	}

	namespace Devices
	{
		class IDriver;
		using IDriverSPtr = std::shared_ptr<IDriver>;

		class BaseDevice : public virtual IDevice
		{
		public:
			BaseDevice(IDriverSPtr pDriver, Core::ITaskQueueSPtr pTaskQueue);
			virtual ~BaseDevice();

			// overrides from IDevice
			void Initialise() override;
			void Shutdown() override;
			void Wait() override;

		protected:
			void InitialiseCallback();
			void ShutdownCallback();

			Core::ITaskQueueSPtr GetCallbackDispatcher() const;
			void BeginAsyncOperation();
			void FinishAsyncOperation();

		private:
			IDriverSPtr m_pDriver;
			Core::ITaskQueueSPtr m_pTaskQueue;
		};
	}
}
