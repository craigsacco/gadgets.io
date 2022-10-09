#pragma once

#include "IDriver.h"

namespace InterfaceIO
{
	namespace Devices
	{
		class IDigitalInputDriver : public virtual IDriver
		{
		public:
			using StateCallbackSPtr = std::shared_ptr<Core::IAsyncCallback<bool>>;

			IDigitalInputDriver() = delete;
			virtual ~IDigitalInputDriver() = delete;

			virtual void BeginGetState(StateCallbackSPtr callback) = 0;
		};
	}
}
