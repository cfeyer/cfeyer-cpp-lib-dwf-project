main: main.cpp
	$(CXX) -o main \
		main.cpp \
		-I../../cfeyer-cpp-api-dwf-project/include \
		-I../include \
		-std=c++11 \
		-Wall -pedantic-errors -Wextra -Wno-unused-parameter -Werror -g \
		-lcfeyer_cpp_lib_dwf -L./libcfeyer_cpp_lib_dwf

.PHONY = clean

clean:
	rm -f main
