#pragma once

#include "Callback.h"
#include "IAsyncCallback.h"
#include "TaskQueue.h"

namespace GadgetsIO
{
	namespace Core
	{
		using ITaskQueueSPtr = std::shared_ptr<ITaskQueue>;

		template <typename... Args>
		class AsyncCallback : public Callback<Args...>, public virtual IAsyncCallback<Args...>
		{
		public:
			AsyncCallback(ITaskQueueSPtr pTaskQueue, ICallback<Args...>::MethodPtr pMethod)
				: Callback<Args...>(pMethod)
				, m_pTaskQueue(pTaskQueue)
			{
			}

			void BeginInvoke(Args... args) override
			{
				m_pTaskQueue->AddTask([this]() { this->Invoke(args...); });
			}

		protected:
			ITaskQueueSPtr m_pTaskQueue;
		};

		template <>
		class AsyncCallback<> : public Callback<>, public virtual IAsyncCallback<>
		{
		public:
			AsyncCallback(ITaskQueueSPtr pTaskQueue, ICallback<>::MethodPtr pMethod)
				: Callback<>(pMethod)
				, m_pTaskQueue(pTaskQueue)
			{
			}

			void BeginInvoke() override
			{
				m_pTaskQueue->AddTask([this]() { this->Invoke(); });
			}

		protected:
			ITaskQueueSPtr m_pTaskQueue;
		};
	}
}
