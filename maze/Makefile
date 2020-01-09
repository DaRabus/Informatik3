CXX = clang++
CXXFLAGS = -c -std=c++17 -W -Wall -Wextra -pedantic -O0 -g
LFLAGS = -lncurses

PROGS = main
OBJS = main.o tremaux.o mapping_agent.o wall_follower.o random_mouse.o \
	mapping_agent.o agent.o maze.o console_screen.o pose.o intvec2.o



.PHONY: all
all: $(PROGS) maze_uml.png



main: $(OBJS)
	$(CXX) -o $@ $^ $(LFLAGS)

main.o: main.cpp wall_follower.h random_mouse.h console_screen.h
	$(CXX) -o $@ $< $(CXXFLAGS)

tremaux.o: tremaux.cpp tremaux.h mapping_agent.h
	$(CXX) -o $@ $< $(CXXFLAGS)

wall_follower.o: wall_follower.cpp wall_follower.h agent.h
	$(CXX) -o $@ $< $(CXXFLAGS)

random_mouse.o: random_mouse.cpp random_mouse.h agent.h
	$(CXX) -o $@ $< $(CXXFLAGS)

mapping_agent.o: mapping_agent.cpp mapping_agent.h agent.h
	$(CXX) -o $@ $< $(CXXFLAGS)

agent.o: agent.cpp agent.h maze.h
	$(CXX) -o $@ $< $(CXXFLAGS)

maze.o: maze.cpp maze.h screen.h pose.h field_type.h
	$(CXX) -o $@ $< $(CXXFLAGS)

console_screen.o: console_screen.cpp console_screen.h screen.h
	$(CXX) -o $@ $< $(CXXFLAGS)

pose.o: pose.cpp pose.h intvec2.h
	$(CXX) -o $@ $< $(CXXFLAGS)

intvec2.o: intvec2.cpp intvec2.h
	$(CXX) -o $@ $< $(CXXFLAGS)


maze_uml.png: maze_uml.puml
	plantuml -tpng -o$<



.PHONY: clean
clean:
	rm -f $(PROGS) $(OBJS) maze_uml.png
