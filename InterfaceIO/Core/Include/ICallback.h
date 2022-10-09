#pragma once

namespace InterfaceIO
{
	namespace Core
	{
		template <typename... Args>
		class ICallback
		{
		public:
			using MethodPtr = void(*)(Args...);

			virtual void Invoke(Args... args) = 0;
		};

		template <>
		class ICallback<>
		{
		public:
			using MethodPtr = void(*)();

			virtual void Invoke() = 0;
		};
	}
}
