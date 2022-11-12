
# Execuate Name
EXENAME = main
# Add standard CS 225 object files
OBJS = file_reader.o main.o

# Compiler/linker comfig and object/depfile directory:
CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement Makefile rule:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")



.PHONY: all test clean output_msg
# Rule for `all` (first/default rule):
all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

# Add More Objects to Compile
main.o: main.cpp file_reader.cpp
	$(CXX) $(CXXFLAGS) main.cpp

file_reader.o: file_reader.cpp
	$(CXX) $(CXXFLAGS) file_reader.cpp


test: output_msg  tests/tests.cpp file_reader.cpp
	$(LD)  tests/tests.cpp file_reader.cpp $(LDFLAGS) -o test

tests.o: tests/tests.cpp  file_reader.cpp
	$(CXX) $(CXXFLAGS) tests/tests.cpp

# Standard C++ Makefile rules:
clean:
	-rm -f *.o $(EXENAME) test