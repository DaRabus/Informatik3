CXX = clang++
CXXFLAGS = -c -std=c++17 -W -Wall -Wextra -pedantic -O0 -g
CXXFLAGS += $(shell pkg-config --cflags opencv) -DENABLE_CXX11
LFLAGS =
LFLAGS += $(shell pkg-config --libs opencv)

PROGS = sinus
OBJS = sinus.o


.PHONY:
all: $(PROGS)


sinus: sinus.o
	$(CXX) -o $@ $^ $(LFLAGS)

sinus.o: sinus.cpp
	$(CXX) -o $@ $< $(CXXFLAGS)


.PHONY: clean
clean:
	rm -f $(PROGS) $(OBJS)
