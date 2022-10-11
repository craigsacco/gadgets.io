add_library(GadgetsIO_Devices_DigitalInput)
add_library(GadgetsIO::Devices::DigitalInput ALIAS GadgetsIO_Devices_DigitalInput)

set_target_properties(GadgetsIO_Devices_DigitalInput PROPERTIES FOLDER "GadgetsIO/Devices")

target_link_libraries(GadgetsIO_Devices_DigitalInput
	PUBLIC	GadgetsIO::Core
			GadgetsIO::Devices::Core
)

target_include_directories(GadgetsIO_Devices_DigitalInput
	PUBLIC	Include
)

target_sources(GadgetsIO_Devices_DigitalInput
	PRIVATE	Include/BaseDigitalInputDriver.h
			Include/DigitalInput.h
			Include/IDigitalInput.h
			Include/IDigitalInputDriver.h
			Source/BaseDigitalInputDriver.cpp
			Source/DigitalInput.cpp
)
