#pragma once

#include "IDriver.h"

namespace InterfaceIO
{
	namespace Devices
	{
		class IDigitalOutputDriver : public virtual IDriver
		{
		public:
			using StateCallbackSPtr = std::shared_ptr<Core::IAsyncCallback<bool>>;

			IDigitalOutputDriver() = delete;
			virtual ~IDigitalOutputDriver() = delete;

			virtual void BeginOn(VoidCallbackSPtr callback) = 0;
			virtual void BeginOff(VoidCallbackSPtr callback) = 0;
			virtual void BeginToggle(VoidCallbackSPtr callback) = 0;
			virtual void BeginGetState(StateCallbackSPtr callback) = 0;
		};
	}
}
