#pragma once

#include <boost/asio/io_context.hpp>

namespace GadgetsIO
{
	namespace Core
	{
		class ITaskQueue
		{
		public:
			ITaskQueue() = delete;

			virtual void AddTask(std::function<void()> task) = 0;
		};
	}
}