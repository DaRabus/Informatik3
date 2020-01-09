CXX = clang++
CXXFLAGS = -c -std=c++17 -W -Wall -Wextra -pedantic -O0 -g
LFLAGS = 

PROG = decomment
OBJS = decomment.o


.PHONY: all
all: $(PROG)


decomment: decomment.o
	$(CXX) -o $@ $^ $(LFLAGS)

decomment.o: decomment.cpp
	$(CXX) -o $@ $< $(CXXFLAGS)


.PHONY: clean
clean:
	rm -f $(PROG) $(OBJS)

