// Christian Kinzer
// cfk5ax
// 9/20/18
// postfixCalculator.cpp

#include "postfixCalculator.h"
#include <iostream>
#include "stack.h"
#include "stackNode.h"

postfixCalculator::postfixCalculator(){ // default constructor
  calcstack = stack();
}

void postfixCalculator::pushNum(int x){ // pushes a number
  calcstack.push(x);
}

bool postfixCalculator::isEmpty(){ // returns true if empty
  return calcstack.empty();
}

void postfixCalculator::makeEmpty(){ // clears the stack
  calcstack = stack();
}

int postfixCalculator::getTopValue(){ // returns top value
  return calcstack.top();
}

void postfixCalculator::add(){ // addition
  int temp = calcstack.top();
  calcstack.pop();
  temp += calcstack.top();
  calcstack.pop();
  calcstack.push(temp);
}

void postfixCalculator::subtract(){ // subtraction
  int temp = calcstack.top();
  calcstack.pop();
  int first = calcstack.top();
  calcstack.pop();
  first -= temp;
  calcstack.push(first);
}

void postfixCalculator::multiply(){ // multiplication
  int temp = calcstack.top();
  calcstack.pop();
  temp *= calcstack.top();
  calcstack.pop();
  calcstack.push(temp);
}

void postfixCalculator::divide(){ // division
  int temp = calcstack.top();
  calcstack.pop();
  int first = calcstack.top();
  calcstack.pop();
  calcstack.push(first/temp);
}

void postfixCalculator::negate(){ // unary negation
  int temp = calcstack.top();
  calcstack.pop();
  calcstack.push(temp * -1);
}

