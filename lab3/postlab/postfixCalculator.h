// Christian Kinzer
// cfk5ax
// 9/20/18
// postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"
using namespace std;


class postfixCalculator {
 public:
  postfixCalculator(); // constructor
  void pushNum(int x); // push a number onto the stack
  void add(); // addition
  void subtract(); // subtraction
  void multiply(); // multiplication
  void divide(); // division
  void negate(); // unary negation;
  int getTopValue(); // returns the top value on the stack
  bool isEmpty(); // returns true if stack is empty
  void makeEmpty(); // clears the stack
 private:
  stack calcstack;
};

#endif
