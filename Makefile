CXX=g++
CXXFLAGS=-g -O3 -Wall -std=c++11

.PHONY: all clean

all: main

main: precompiledHeader main.cpp util.cpp multi_stage.cpp arithmetic.cpp geometric.cpp 
	$(CXX) $(CXXFLAGS) main.cpp util.cpp multi_stage.cpp arithmetic.cpp geometric.cpp -o main

precompiledHeader: util.hpp multi_stage.hpp arithmetic.hpp geometric.hpp
	$(CXX) $(CXXFLAGS) util.hpp multi_stage.hpp arithmetic.hpp geometric.hpp

clean:
	rm -f *.gch *.exe