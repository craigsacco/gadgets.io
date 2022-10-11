#pragma once

#include "BaseDriver.h"
#include "IDigitalOutputDriver.h"

namespace InterfaceIO
{
	namespace Devices
	{
		class BaseDigitalOutputDriver : public BaseDriver, public virtual IDigitalOutputDriver
		{
		public:
			explicit BaseDigitalOutputDriver(Core::ITaskQueueSPtr pTaskQueue);
			~BaseDigitalOutputDriver();

			void BeginOn(VoidCallbackSPtr pCallback) override;
			void BeginOff(VoidCallbackSPtr pCallback) override;
			void BeginToggle(VoidCallbackSPtr pCallback) override;
			void BeginGetState(StateCallbackSPtr pCallback) override;

		protected:
			virtual void On() = 0;
			virtual void Off() = 0;
			virtual void Toggle() = 0;
			virtual void GetState() = 0;

		protected:
			StateCallbackSPtr m_pGetStateCallback = nullptr;
		};
	}
}
