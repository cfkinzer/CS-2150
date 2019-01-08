// Christian Kinzer
// cfk5ax
// 9/20/18
// stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stackNode.h"
using namespace std;

class stack {
 public:
  stack(); // constructor
  ~stack(); // destructor
  bool empty(); // is this shit empty or not
  void push(int x); // push that shit on here
  void pop(); // pop that shit off
  int top(); // return the top of that shit
 private:
  stackNode * head, * tail;
  int count;
};

#endif
