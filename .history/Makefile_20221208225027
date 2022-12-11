EXENAME = main
OBJS = file_reader.o main.o airport_graph.o edge.o airport.o dijikstra.o BFS.o pagerank.o

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


main.o: src/main.cpp src/file_reader.h src/airport_graph.h src/edge.h src/airport.h
	$(CXX) $(CXXFLAGS)  src/main.cpp

file_reader.o: src/file_reader.cpp src/file_reader.h
	$(CXX) $(CXXFLAGS) src/file_reader.cpp

airport_graph.o: src/airport_graph.cpp src/airport_graph.h
	$(CXX) $(CXXFLAGS) src/airport_graph.cpp

edge.o: src/edge.cpp src/edge.h
	$(CXX) $(CXXFLAGS) src/edge.cpp

airport.o: src/airport.cpp src/airport.h
	$(CXX) $(CXXFLAGS) src/airport.cpp

dijikstra.o: src/dijikstra.cpp src/dijikstra.h
	$(CXX) $(CXXFLAGS) src/dijikstra.cpp

BFS.o: src/BFS.cpp src/BFS.h
	$(CXX) $(CXXFLAGS) src/BFS.cpp

pagerank.o: src/pagerank.cpp src/pagerank.h
	$(CXX) $(CXXFLAGS) src/pagerank.cpp

test: output_msg tests/catch/catchmain.cpp tests/tests.cpp src/file_reader.cpp src/airport.cpp src/edge.cpp src/airport_graph.cpp src/pagerank.cpp src/dijikstra.cpp src/BFS.cpp
	$(LD) tests/catch/catchmain.cpp tests/tests.cpp  src/file_reader.cpp src/airport.cpp src/edge.cpp src/airport_graph.cpp src/pagerank.cpp src/dijikstra.cpp src/BFS.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test