## compiler
CXX = clang++

## compiler flags
#CXXFLAGS = -Wall -Werror -O2
## enable this for debugging
#CXXFLAGS = -Wall -g


# variables from gtest makefile
GTEST_DIR = /Users/pdc/Software/gtest-1.7.0
USER_DIR = .
CPPFLAGS += -isystem $(GTEST_DIR)/include 
CXXFLAGS += -g
TESTS = testBishopMovement testCheckmate

# include header files for gtest library
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

default: clean test

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# for the test
gambitov.o : $(USER_DIR)/gambitov.cpp $(USER_DIR)/gambitov.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/gambitov.cpp

testPieceMovement.o : $(USER_DIR)/testPieceMovement.cpp \
                     $(USER_DIR)/gambitov.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/testPieceMovement.cpp

testCheckmate.o : $(USER_DIR)/testCheckmate.cpp \
                     $(USER_DIR)/gambitov.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/testCheckmate.cpp



testPieceMovement: gambitov.o testPieceMovement.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

testCheckmate: gambitov.o testCheckmate.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

test: testCheckmate testPieceMovement
	./testCheckmate
	./testPieceMovement



# end of things from gtest makefile

SOURCES = $(wildcard *.cpp)
OBJECTS = $(subst .cpp,,$(SOURCES))

.PHONY: % 


## using this target will automagically compile all the *.cpp
## files (hopefully tests) found in the current directory into
## individual binaries
all: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) 
	echo "Compilation Successful!"
	./a.out


mytest: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) $(GTEST)
	echo "Compilation Successful!"
	./a.out

clean: 
	rm -f *.o a.out core out? $(OBJECTS) exe
	rm -f $(TESTS) gtest.a gtest_main.a *.o


