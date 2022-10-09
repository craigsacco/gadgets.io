#pragma once

#include "IAsyncCallback.h"

namespace InterfaceIO
{
	namespace Devices
	{
		class IDriver
		{
		public:
			using VoidCallbackSPtr = std::shared_ptr<Core::IAsyncCallback<>>;

			IDriver() = delete;
			virtual ~IDriver() = delete;

			virtual void BeginInitialise(VoidCallbackSPtr callback) = 0;
			virtual void BeginShutdown(VoidCallbackSPtr callback) = 0;
		};
	}
}