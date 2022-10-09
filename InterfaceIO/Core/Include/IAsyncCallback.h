#pragma once

#include "ICallback.h"

namespace InterfaceIO
{
	namespace Core
	{
		template <typename... Args>
		class IAsyncCallback : public virtual ICallback<Args...>
		{
		public:			
			virtual void BeginInvoke(Args... args) = 0;
		};

		template <>
		class IAsyncCallback<> : public virtual ICallback<>
		{
		public:
			virtual void BeginInvoke() = 0;
		};
	}
}
