// Christian Kinzer
// cfk5ax
// 10/23/18
// 9:30 AM Lab
// hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "timer.h"

using namespace std;

class hashTable {
 public:
  hashTable(int size);
  bool contains(string s);
  int hash(string s) const;
  void insert(string s);
  int getNextPrime(unsigned int n);
  bool checkprime(unsigned int p);
  int longest;
 private:
  vector<list<string> > fuckthislab;
  int sizey;
  unsigned int thirtysevens[22];
};

#endif
