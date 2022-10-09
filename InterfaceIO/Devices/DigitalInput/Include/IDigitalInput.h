#pragma once

#include "IDevice.h"

namespace InterfaceIO
{
	namespace Devices
	{
		class IDigitalInput : public virtual IDevice
		{
		public:
			virtual bool GetState() = 0;
		};
	}
}
