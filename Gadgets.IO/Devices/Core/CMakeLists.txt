add_library(GadgetsIO_Devices_Core)
add_library(GadgetsIO::Devices::Core ALIAS GadgetsIO_Devices_Core)

set_target_properties(GadgetsIO_Devices_Core PROPERTIES FOLDER "GadgetsIO/Devices")

target_link_libraries(GadgetsIO_Devices_Core
	PUBLIC	GadgetsIO::Core
)

target_include_directories(GadgetsIO_Devices_Core
	PUBLIC	Include
)

target_sources(GadgetsIO_Devices_Core
	PRIVATE	Include/BaseDevice.h
			Include/BaseDriver.h
			Include/IDevice.h
			Include/IDriver.h
			Source/BaseDevice.cpp
			Source/BaseDriver.cpp
)
