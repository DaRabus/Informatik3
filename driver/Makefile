CXX = clang++
CXXFLAGS = -c -std=c++17 -W -Wall -Wextra -pedantic -O0 -g
LFLAGS = 

PROG = main
OBJS = main.o sensor_constants.o serial.o crc16.o


.PHONY: all
all: $(PROG)


main: $(OBJS)
	$(CXX) -o $@ $^ $(LFLAGS)


main.o: main.cpp serial.h
	$(CXX) -o $@ $< $(CXXFLAGS)

sensor_constants.o: sensor_constants.cpp sensor_constants.h
	$(CXX) -o $@ $< $(CXXFLAGS)

serial.o: serial.cpp serial.h
	$(CXX) -o $@ $< $(CXXFLAGS)

crc16.o: crc16.cpp crc16.h
	$(CXX) -o $@ $< $(CXXFLAGS)


.PHONY: clean
clean:
	rm -f $(PROG) $(OBJS)

