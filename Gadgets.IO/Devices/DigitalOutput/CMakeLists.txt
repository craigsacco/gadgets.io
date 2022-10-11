add_library(GadgetsIO_Devices_DigitalOutput)
add_library(GadgetsIO::Devices::DigitalOutput ALIAS GadgetsIO_Devices_DigitalOutput)

set_target_properties(GadgetsIO_Devices_DigitalOutput PROPERTIES FOLDER "GadgetsIO/Devices")

target_link_libraries(GadgetsIO_Devices_DigitalOutput
	PUBLIC	GadgetsIO::Core
			GadgetsIO::Devices::Core
)

target_include_directories(GadgetsIO_Devices_DigitalOutput
	PUBLIC	Include
)

target_sources(GadgetsIO_Devices_DigitalOutput
	PRIVATE	Include/BaseDigitalOutputDriver.h
			Include/DigitalOutput.h
			Include/IDigitalOutput.h
			Include/IDigitalOutputDriver.h
			Source/BaseDigitalOutputDriver.cpp
			Source/DigitalOutput.cpp
)
