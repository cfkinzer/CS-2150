#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
  BinaryNode();
  ~BinaryNode();

  string value;
  BinaryNode* left;
  BinaryNode* right;

  string pathTo(const string& x);

  friend class BinarySearchTree;
};

#endif
