#Christian Kinzer
#cfk5ax
#10/23/18
#9:30 AM Lab
#Makefile-puzzle

CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -O2 -std=c++11
DEBUG=-Wall -g
OFILES = hashTable.o timer.o wordPuzzle.o
.SUFFIXES: .o .cpp

puzzle: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	@echo "success"
clean:
	-rm -f *.o *~ puzzle

wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
hashTable.o: hashTable.cpp hashTable.h timer.h
timer.o: timer.cpp timer.h
