// Christian Kinzer
// cfk5ax
// 10/23/18
// 9:30 AM Lab
// hashTable.cpp

#include "hashTable.h"

hashTable::hashTable(int size) {
  longest = 0;
  unsigned int size2 = size * 2;
  sizey = getNextPrime(size2);
  fuckthislab = vector<list<string> >(sizey);
  unsigned int n = 37;
  for (int i = 0; i < 22; i++) {
    thirtysevens[i] = n;
    n *= 37;
  }
}

bool hashTable::contains(string s) {
  list<string> temp = fuckthislab.at(hash(s));
  return (find(temp.begin(), temp.end(), s) != temp.end());
}

int hashTable::hash(string s) const {
  unsigned int val = 0;
  for (int i = 0; i < s.size(); i++) {
    val += s[i]*thirtysevens[i];
  }
  return val % sizey;
}

void hashTable::insert(string s) {
  fuckthislab.at(hash(s)).push_back(s);
  if (s.length() > longest)
    longest = s.length();
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
  
  
