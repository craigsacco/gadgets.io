add_library(InterfaceIO_Devices_DigitalInput)
add_library(InterfaceIO::Devices::DigitalInput ALIAS InterfaceIO_Devices_DigitalInput)

set_target_properties(InterfaceIO_Devices_DigitalInput PROPERTIES FOLDER "InterfaceIO/Devices")

target_link_libraries(InterfaceIO_Devices_DigitalInput
	PUBLIC	InterfaceIO::Core
			InterfaceIO::Devices::Core
)

target_include_directories(InterfaceIO_Devices_DigitalInput
	PUBLIC	Include
)

target_sources(InterfaceIO_Devices_DigitalInput
	PRIVATE	Include/DigitalInput.h
			Include/IDigitalInput.h
			Include/IDigitalInputDriver.h
			Source/DigitalInput.cpp
)
