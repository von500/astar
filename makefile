
test: test.cpp
	g++ -std=c++11 test.cpp -o test

test.cpp: astar.hpp

.PHONY: clean
clean:
	rm test.exe
