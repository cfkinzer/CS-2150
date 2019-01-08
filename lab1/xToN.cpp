// Christian Kinzer
// cfk5ax
// 9/2/18
// xToN.cpp
// 9:30 AM lab

#include <iostream>
using namespace std;

int xton(int a, int b) {
  if (b == 1)
    return a;
  if (b == 0)
    return 1;
  else
    return a * xton(a, b-1);
}

int main() {
  int x, n;
  cout << "Enter the base of the exponential expression." << endl;
  cin >> x;
  cout << "Enter the exponent of the exponential expression." << endl;
  cin >> n;
  cout << x <<  " to the power of " << n << " is " << xton(x, n) << "." << endl;
  return 0;
}
