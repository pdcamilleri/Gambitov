## compiler
CXX = clang++

## compiler flags
CXXFLAGS = -Wall -Werror -O2
## enable this for debugging
#CXXFLAGS = -Wall -g

SOURCES = $(wildcard *.cpp)
OBJECTS = $(subst .cpp,,$(SOURCES))

.PHONY: % 

default: all

## using this target will automagically compile all the *.cpp
## files (hopefully tests) found in the current directory into
## individual binaries
all: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) 
	echo "Compilation Successful!"
	./a.out

clean: 
	rm -f *.o a.out core out? $(OBJECTS) exe
