all: $(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/device_enumeration_cpp \
     $(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/analogoutin_cpp \
     $(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/analogout_custom_cpp


$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/device_enumeration_cpp: device_enumeration.cpp
	$(CXX) -o $@ \
		device_enumeration.cpp \
		-I$(CFEYER_CPP_API_DWF_PROJECT_ROOT)/include \
		-I$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/include \
		-std=c++98 \
		-Wall -pedantic-errors -Wextra -Wno-unused-parameter -Werror -g -Wno-unused-variable \
		-lcfeyer_cpp_lib_dwf -L$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/lib

$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/analogoutin_cpp: analogoutin.cpp
	$(CXX) -o $@ \
		analogoutin.cpp \
		-I$(CFEYER_CPP_API_DWF_PROJECT_ROOT)/include \
		-I$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/include \
		-std=c++98 \
		-Wall -pedantic-errors -Wextra -Wno-unused-parameter -Werror -g -Wno-unused-variable \
		-lcfeyer_cpp_lib_dwf -L$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/lib

$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/analogout_custom_cpp: analogout_custom.cpp
	$(CXX) -o $@ \
		analogout_custom.cpp \
		-I$(CFEYER_CPP_API_DWF_PROJECT_ROOT)/include \
		-I$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/include \
		-std=c++98 \
		-Wall -pedantic-errors -Wextra -Wno-unused-parameter -Werror -g -Wno-unused-variable -Wno-unused-but-set-variable \
		-lcfeyer_cpp_lib_dwf -L$(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/lib

.PHONY = all clean

clean:
	rm -f $(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/device_enumeration_cpp
	rm -f $(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/analogoutin_cpp
	rm -f $(CFEYER_CPP_LIB_DWF_PROJECT_ROOT)/bin/analogout_custom_cpp
