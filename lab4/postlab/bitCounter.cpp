// Christian Kinzer
// cfk5ax
// 9/26/18
// bitCounter.cpp

#include <iostream>
#include <stdlib.h>
using namespace std;

int bitCounter(int x) {
  if (x == 0) {
    return 0;
  }
  if (x == 1) {
    return 1;
  }
  if (x % 2 == 0) {
    return bitCounter(x/2);
  }
  if (x % 2 != 0) {
    return bitCounter(x/2) + 1;
  }
}

int main(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    cout << bitCounter(atoi(argv[i])) << endl;
  }
  return 0;
}
