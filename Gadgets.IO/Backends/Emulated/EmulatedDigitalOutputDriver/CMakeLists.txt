# Copyright (C) 2022 Craig Sacco
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

add_library(GadgetsIO_Backends_EmulatedDigitalOutputDriver)
add_library(GadgetsIO::Backends::EmulatedDigitalOutputDriver ALIAS GadgetsIO_Backends_EmulatedDigitalOutputDriver)

set_target_properties(GadgetsIO_Backends_EmulatedDigitalOutputDriver PROPERTIES FOLDER "GadgetsIO/Backends/Emulated")

target_link_libraries(GadgetsIO_Backends_EmulatedDigitalOutputDriver
	PUBLIC	GadgetsIO::Devices::DigitalOutput
)

target_include_directories(GadgetsIO_Backends_EmulatedDigitalOutputDriver
	PUBLIC	Include
)

target_sources(GadgetsIO_Backends_EmulatedDigitalOutputDriver
	PRIVATE	Include/EmulatedDigitalOutputDriver.h
			Source/EmulatedDigitalOutputDriver.cpp
)
