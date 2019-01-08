// Christian Kinzer
// cfk5ax
// 9/20/18
// stackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
using namespace std;

class stackNode {
 public:
  stackNode(); // constructor
 private:
  int value;
  stackNode * next;
  friend class stack;
};

#endif
