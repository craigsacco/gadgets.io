#pragma once

#include "BaseDevice.h"
#include "IDigitalInput.h"

namespace InterfaceIO
{
	namespace Devices
	{
		class IDigitalInputDriver;
		using IDigitalInputDriverSPtr = std::shared_ptr<IDigitalInputDriver>;

		class DigitalInput : public BaseDevice, public virtual IDigitalInput
		{
		public:
			DigitalInput(IDigitalInputDriverSPtr pDriver, Core::ITaskQueueSPtr pTaskQueue);
			virtual ~DigitalInput();

			// overrides from IDigitalInput
			bool GetState() override;

		protected:
			void GetStateCallback(bool state);

		private:
			IDigitalInputDriverSPtr m_pDigitalInputDriver;
			bool m_state;
		};
	}
}
