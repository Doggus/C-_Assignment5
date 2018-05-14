all : audio

INCLUDE_DIRS =
CPPFLAGS = $(INCLUDE_DIRS) -std=c++11

LIB_DIRS = 
LIBS = 
LDFLAGS = $(LIBS) $(LIB_DIRS) -fPIC
OBJECTS = main.o
PROGRAM = audio

$(PROGRAM) : $(OBJECTS)
	g++  $(OBJECTS) -o $(PROGRAM) $(LDFLAGS)

Audio.o : Audio.h
	g++ -c vec.h.cpp $(CPPFLAGS)

main.o : main.cpp Audio.h
	g++ -c main.cpp $(CPPFLAGS)

run :
	./$(PROGRAM)

clean :
	rm *.o

test: UnitTests.cpp
	g++ -o UnitTests UnitTests.cpp Audio.h -std=c++11

runTest:
	./UnitTests
