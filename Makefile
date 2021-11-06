CXX=g++
CXXFLAGS=-g -O3 -Wall -std=c++11

.PHONY: all clean

all: main

main: precompiledHeader main.cpp multi_stage.cpp arithmetic.cpp geometric.cpp fibonacci.cpp
	$(CXX) $(CXXFLAGS) main.cpp multi_stage.cpp arithmetic.cpp exponent.cpp geometric.cpp fibonacci.cpp -o main

precompiledHeader: header.hpp utility.hpp multi_stage.hpp arithmetic.hpp geometric.hpp fibonacci.hpp
	$(CXX) $(CXXFLAGS) header.hpp utility.hpp multi_stage.hpp arithmetic.hpp exponent.hpp geometric.hpp fibonacci.hpp

clean:
	rm -f *.gch *.exe
