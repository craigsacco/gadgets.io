#pragma once

#include "BaseDigitalInputDriver.h"
#include "IDigitalInputDriver.h"

namespace GadgetsIO
{
	namespace Backends
	{
		namespace Emulated
		{
			class EmulatedDigitalInputDriver : public Devices::BaseDigitalInputDriver
			{
			public:
				explicit EmulatedDigitalInputDriver(Core::ITaskQueueSPtr pTaskQueue);
				~EmulatedDigitalInputDriver();

				void BeginSetState(bool state, VoidCallbackSPtr pCallback);

			private:
				// overrides from BaseDriver
				void Initialise() override;
				void Shutdown() override;

				// overrides from BaseDigitalInputDriver
				void GetState() override;

				void SetState(bool state);

			private:
				bool m_state = false;
			};
		}
	}
}
