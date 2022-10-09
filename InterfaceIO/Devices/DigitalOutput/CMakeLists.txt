add_library(InterfaceIO_Devices_DigitalOutput)
add_library(InterfaceIO::Devices::DigitalOutput ALIAS InterfaceIO_Devices_DigitalOutput)

set_target_properties(InterfaceIO_Devices_DigitalOutput PROPERTIES FOLDER "InterfaceIO/Devices")

target_link_libraries(InterfaceIO_Devices_DigitalOutput
	PUBLIC	InterfaceIO::Core
			InterfaceIO::Devices::Core
)

target_include_directories(InterfaceIO_Devices_DigitalOutput
	PUBLIC	Include
)

target_sources(InterfaceIO_Devices_DigitalOutput
	PRIVATE	Include/DigitalOutput.h
			Include/IDigitalOutput.h
			Include/IDigitalOutputDriver.h
			Source/DigitalOutput.cpp
)
