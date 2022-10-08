add_library(InterfaceIO_Core)
add_library(InterfaceIO::Core ALIAS InterfaceIO_Core)

set_target_properties(InterfaceIO_Core PROPERTIES FOLDER "InterfaceIO/Core")

target_link_libraries(InterfaceIO_Core
	PUBLIC	Boost::asio
)

target_include_directories(InterfaceIO_Core
	PUBLIC	Include
)

target_sources(InterfaceIO_Core
	PUBLIC	Include/TaskQueue.h
			Source/TaskQueue.cpp
)
