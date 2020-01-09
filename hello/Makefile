CXX = clang++
CXXFLAGS = -c -std=c++17 -W -Wall -Wextra -pedantic -O0 -g
CXXFLAGS += $(shell pkg-config --cflags opencv) -DENABLE_CXX11
LFLAGS =
LFLAGS += $(shell pkg-config --libs opencv)

PROGS = hello
OBJS = hello.o


.PHONY:
all: $(PROGS)


hello: hello.o
	$(CXX) -o $@ $^ $(LFLAGS)

hello.o: hello.cpp
	$(CXX) -o $@ $< $(CXXFLAGS)


.PHONY: clean
clean:
	rm -f $(PROGS) $(OBJS)
