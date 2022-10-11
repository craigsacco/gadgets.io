#include "AsyncClassCallback.h"
#include "DigitalOutput.h"
#include "IDigitalOutputDriver.h"

namespace InterfaceIO
{
	namespace Devices
	{
		DigitalOutput::DigitalOutput(IDigitalOutputDriverSPtr pDriver, Core::ITaskQueueSPtr pTaskQueue)
			: BaseDevice(pDriver, pTaskQueue)
			, m_pDigitalOutputDriver(pDriver)
		{
		}

		DigitalOutput::~DigitalOutput()
		{
		}

		void DigitalOutput::On()
		{
			BeginAsyncOperation();

			const auto pCallback = std::make_shared<Core::AsyncClassCallback<DigitalOutput>>(
				GetCallbackDispatcher(), this, &DigitalOutput::DefaultCallback);
			m_pDigitalOutputDriver->BeginOn(pCallback);
		}

		void DigitalOutput::Off()
		{
			BeginAsyncOperation();

			const auto pCallback = std::make_shared<Core::AsyncClassCallback<DigitalOutput>>(
				GetCallbackDispatcher(), this, &DigitalOutput::DefaultCallback);
			m_pDigitalOutputDriver->BeginOff(pCallback);
		}

		void DigitalOutput::Toggle()
		{
			BeginAsyncOperation();

			const auto pCallback = std::make_shared<Core::AsyncClassCallback<DigitalOutput>>(
				GetCallbackDispatcher(), this, &DigitalOutput::DefaultCallback);
			m_pDigitalOutputDriver->BeginToggle(pCallback);
		}

		void DigitalOutput::DefaultCallback()
		{
			FinishAsyncOperation();
		}

		bool DigitalOutput::GetState()
		{
			BeginAsyncOperation();

			const auto pCallback = std::make_shared<Core::AsyncClassCallback<DigitalOutput, bool>>(
				GetCallbackDispatcher(), this, &DigitalOutput::GetStateCallback);
			m_pDigitalOutputDriver->BeginGetState(pCallback);

			Wait();
			return m_state;
		}

		void DigitalOutput::GetStateCallback(bool state)
		{
			m_state = state;

			FinishAsyncOperation();
		}
	}
}
