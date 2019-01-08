// Christian Kinzer
// cfk5ax
// 9/17/18
// testPostfixCalc.cpp

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include "postfixCalculator.h"
using namespace std;

int main(){
  postfixCalculator p;
  p.pushNum(1);
  p.pushNum(2);
  p.pushNum(3);
  p.pushNum(4);
  p.pushNum(5);
  p.add();
  p.add();
  p.add();
  p.add();
  cout << "Result is: " << p.getTopValue() << endl;
  return 0;
}
