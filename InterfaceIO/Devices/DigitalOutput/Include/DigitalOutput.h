#pragma once

#include "BaseDevice.h"
#include "IDigitalOutput.h"

namespace InterfaceIO
{
	namespace Devices
	{
		class IDigitalOutputDriver;
		using IDigitalOutputDriverSPtr = std::shared_ptr<IDigitalOutputDriver>;

		class DigitalOutput : public BaseDevice, public virtual IDigitalOutput
		{
		public:
			DigitalOutput(IDigitalOutputDriverSPtr pDriver, Core::ITaskQueueSPtr pTaskQueue);
			virtual ~DigitalOutput();

			// overrides from IDigitalOutput
			void On() override;
			void Off() override;
			void Toggle() override;
			bool GetState() override;

		protected:
			void DefaultCallback();
			void GetStateCallback(bool state);

		private:
			IDigitalOutputDriverSPtr m_pDigitalOutputDriver;
			bool m_state;
		};
	}
}
