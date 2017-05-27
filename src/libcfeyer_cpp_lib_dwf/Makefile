# MIT License
# 
# Copyright (c) 2017 Chris Feyerchak
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/lib/libcfeyer_cpp_lib_dwf.so: Device_Enumerator.cpp DWF_Call_Exception.cpp Device.cpp Analog_Output_Channel.cpp Analog_Output_Channels.cpp Open_Device.cpp Library.cpp Library_Implementation.cpp
	$(CXX) -o $@ \
		-shared -fPIC \
		Device_Enumerator.cpp DWF_Call_Exception.cpp Device.cpp Analog_Output_Channel.cpp Analog_Output_Channels.cpp Open_Device.cpp Library.cpp Library_Implementation.cpp \
		-I$(CFEYER_CPP_API_DWF_PROJECT_ROOT)/include \
		-I$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/include \
		-std=c++11 \
		-Wall -pedantic-errors -Wextra -Wno-unused-parameter -Werror -g \
		-ldwf

.PHONY = clean

clean:
	rm -f $(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/lib/libcfeyer_cpp_lib_dwf.so
