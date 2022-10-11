#pragma once

#include "ClassCallback.h"
#include "IAsyncCallback.h"
#include "TaskQueue.h"

namespace GadgetsIO
{
	namespace Core
	{
		using ITaskQueueSPtr = std::shared_ptr<ITaskQueue>;

		template <class TClass, typename... Args>
		class AsyncClassCallback : public ClassCallback<TClass, Args...>, public virtual IAsyncCallback<Args...>
		{
		public:
			AsyncClassCallback(ITaskQueueSPtr pTaskQueue, ClassCallback<TClass, Args...>::ClassConstPtr pTarget, ClassCallback<TClass, Args...>::MemberMethod method)
				: ClassCallback<TClass, Args...>(pTarget, method)
				, m_pTaskQueue(pTaskQueue)
			{
			}

			void BeginInvoke(Args... args) override
			{
				m_pTaskQueue->AddTask([this, ... args = std::forward<Args>(args)]() {
					this->Invoke(args...);
				});
			}

		protected:
			ITaskQueueSPtr m_pTaskQueue;
		};

		template <class TClass>
		class AsyncClassCallback<TClass> : public ClassCallback<TClass>, public virtual IAsyncCallback<>
		{
		public:
			AsyncClassCallback(ITaskQueueSPtr pTaskQueue, ClassCallback<TClass>::ClassConstPtr pTarget, ClassCallback<TClass>::MemberMethod method)
				: ClassCallback<TClass>(pTarget, method)
				, m_pTaskQueue(pTaskQueue)
			{
			}

			void BeginInvoke() override
			{
				m_pTaskQueue->AddTask([this]() {
					this->Invoke();
				});
			}

		protected:
			ITaskQueueSPtr m_pTaskQueue;
		};
	}
}
