EXENAME = main
OBJS = file_reader.o main.o airport_graph.o edge.o airport.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement Makefile rule:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)


main.o: main.cpp file_reader.h
	$(CXX) $(CXXFLAGS)  main.cpp

file_reader.o: file_reader.cpp
	$(CXX) $(CXXFLAGS) file_reader.cpp

airport_graph.o: airport_graph.cpp
	$(CXX) $(CXXFLAGS) airport_graph.cpp

edge.o: edge.cpp
	$(CXX) $(CXXFLAGS) edge.cpp

airport.o: airport.cpp
	$(CXX) $(CXXFLAGS) airport.cpp

test: output_msg tests/catch/catchmain.cpp tests/tests.cpp file_reader.cpp
	$(LD) tests/catch/catchmain.cpp tests/tests.cpp file_reader.cpp $(LDFLAGS) -o test

tests.o: tests/tests.cpp tests/catch/catch.hpp file_reader.cpp airport_graph.cpp edge.cpp airport.cpp 
	$(CXX) $(CXXFLAGS) tests/tests.cpp

clean:
	-rm -f *.o $(EXENAME) test