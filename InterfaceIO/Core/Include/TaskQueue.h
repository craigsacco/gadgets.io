#pragma once

#include <boost/asio/io_context.hpp>

namespace InterfaceIO
{
	namespace Core
	{
		class TaskQueue
		{
		public:
			explicit TaskQueue() = default;
			~TaskQueue();

			TaskQueue(const TaskQueue&) = delete;
			TaskQueue& operator=(const TaskQueue&) = delete;

			void Start();
			void Stop();

			void AddTask(std::function<void()> task);

		protected:
			void ThreadLoop();

		private:
			boost::asio::io_context m_context;
			std::shared_ptr<std::thread> m_pThread;
			bool m_shutdown = false;
		};
	}
}