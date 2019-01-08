// Christian Kinzer
// cfk5ax
// 11/19/18
// 9:30 AM
// threexinput.cpp

#include "timer.h"
#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int threexplusone(int);

int main() {
  int param;
  int n;
  cout << "Please enter a number." << endl;
  cin >> param;
  cout << "How many times to run?" << endl;
  cin >> n;
  timer t;
  t.start();
  for (int i = 0; i < n; i++) {
    threexplusone(param);
  }
  t.stop();
  double avg = t.getTime() / n;
  cout << "Result: " << threexplusone(param) << endl;
  cout << "Average time was: " << avg << endl;
  return 0;
}
