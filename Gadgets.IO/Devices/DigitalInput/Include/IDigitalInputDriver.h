#pragma once

#include "IDriver.h"

namespace GadgetsIO
{
	namespace Devices
	{
		class IDigitalInputDriver : public virtual IDriver
		{
		public:
			using StateCallbackSPtr = std::shared_ptr<Core::IAsyncCallback<bool>>;

			virtual void BeginGetState(StateCallbackSPtr pCallback) = 0;
		};
	}
}
