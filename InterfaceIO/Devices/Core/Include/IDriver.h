#pragma once

#include "IAsyncCallback.h"

#include <memory>

namespace InterfaceIO
{
	namespace Devices
	{
		class IDriver
		{
		public:
			using VoidCallbackSPtr = std::shared_ptr<Core::IAsyncCallback<>>;

			virtual void BeginInitialise(VoidCallbackSPtr pCallback) = 0;
			virtual void BeginShutdown(VoidCallbackSPtr pCallback) = 0;
		};
	}
}