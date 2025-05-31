PROJECT = mikmik
CXX = g++
CXXFLAGS = -O2 -std=c++17 -fopenmp -Werror -Wpedantic -Wall
LDFLAGS = -fopenmp
LGTESTFLAGS = -lgtest -lgtest_main -pthread -fopenmp

DEPS = $(wildcard *.hpp)
OBJ = Rotatebmp.o

.PHONY: default
default: all

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

$(PROJECT): main.o $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ main.o $(OBJ)

all: $(PROJECT)

.PHONY: clean cleanall

clean:
	rm -f *.o

cleanall: clean
	rm -f $(PROJECT)
