#pragma once

#include "BaseDriver.h"
#include "IDigitalInputDriver.h"

namespace InterfaceIO
{
	namespace Devices
	{
		class BaseDigitalInputDriver : public BaseDriver, public virtual IDigitalInputDriver
		{
		public:
			explicit BaseDigitalInputDriver(Core::ITaskQueueSPtr pTaskQueue);
			~BaseDigitalInputDriver();

			void BeginGetState(StateCallbackSPtr pCallback) override;

		protected:
			virtual void GetState() = 0;

		protected:
			StateCallbackSPtr m_pGetStateCallback = nullptr;
		};
	}
}
