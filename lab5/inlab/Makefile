#Christian Kinzer
#cfk5ax
#9:30 AM Lab
#Makefile-bst

CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -O2
DEBUG=-Wall -g
OFILES = BinaryNode.o BinarySearchTree.o BSTPathTest.o
.SUFFIXES: .o .cpp

bst: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	@echo "success"
clean:
	-rm -f *.o *~ bst

BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

