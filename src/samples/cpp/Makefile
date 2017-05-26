$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/device_enumeration_cpp: device_enumeration.cpp
	$(CXX) -o $@ \
		device_enumeration.cpp \
		-I$(CFEYER_CPP_API_DWF_PROJECT_ROOT)/include \
		-I$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/include \
		-std=c++11 \
		-Wall -pedantic-errors -Wextra -Wno-unused-parameter -Werror -g \
		-lcfeyer_cpp_lib_dwf -L$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/lib

.PHONY = clean

clean:
	rm -f $(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/device_enumeration
