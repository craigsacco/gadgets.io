#pragma once

#include "IDevice.h"

namespace InterfaceIO
{
	namespace Devices
	{
		class IDigitalOutput : public virtual IDevice
		{
		public:
			virtual void On() = 0;
			virtual void Off() = 0;
			virtual void Toggle() = 0;
			virtual bool GetState() = 0;
		};
	}
}
