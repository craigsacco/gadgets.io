add_library(GadgetsIO_Core)
add_library(GadgetsIO::Core ALIAS GadgetsIO_Core)

set_target_properties(GadgetsIO_Core PROPERTIES FOLDER "GadgetsIO/Core")

target_link_libraries(GadgetsIO_Core
	PUBLIC	Boost::asio
)

target_include_directories(GadgetsIO_Core
	PUBLIC	Include
)

target_sources(GadgetsIO_Core
	PRIVATE	Include/AsyncCallback.h
			Include/AsyncClassCallback.h
			Include/Callback.h
			Include/ClassCallback.h
			Include/IAsyncCallback.h
			Include/ICallback.h
			Include/ITaskQueue.h
			Include/TaskQueue.h
			Source/TaskQueue.cpp
)
