add_library(InterfaceIO_Devices_Core)
add_library(InterfaceIO::Devices::Core ALIAS InterfaceIO_Devices_Core)

set_target_properties(InterfaceIO_Devices_Core PROPERTIES FOLDER "InterfaceIO/Devices")

target_link_libraries(InterfaceIO_Devices_Core
	PUBLIC	InterfaceIO::Core
)

target_include_directories(InterfaceIO_Devices_Core
	PUBLIC	Include
)

target_sources(InterfaceIO_Devices_Core
	PRIVATE	Include/BaseDevice.h
			Include/BaseDriver.h
			Include/IDevice.h
			Include/IDriver.h
			Source/BaseDevice.cpp
			Source/BaseDriver.cpp
)
