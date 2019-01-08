// Christian Kinzer
// cfk5ax
// 9:30 AM Lab
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
  stacklord = stack<TreeNode*>();
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
  while (stacklord.size() != 0) {
    cleanTree(stacklord.top());
    stacklord.pop();
  }
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  if (ptr->left != NULL) {
    cleanTree(ptr->left);
    cleanTree(ptr->right);
  }
  else
    delete ptr;
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  if (val == "+" || val == "-" || val == "*" || val == "/") {
    TreeNode* math = new TreeNode(val);
    math->left = stacklord.top();
    stacklord.pop();
    math->right = stacklord.top();
    stacklord.pop();
    stacklord.push(math);
  }
  else {
    TreeNode* num = new TreeNode(val);
    stacklord.push(num);
  }
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
  if (ptr->left != NULL || ptr->right != NULL) {
    cout << ptr->value;
    cout << " ";
    printPrefix(ptr->right);
    cout << " ";
    printPrefix(ptr->left);
  }
  else
    cout << ptr->value;
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
  if (ptr->left != NULL) {
    if (ptr->value == "+" || ptr->value == "-" || ptr->value == "*" || ptr->value == "/") {
      cout << "(";
      printInfix(ptr->right);
      cout << " " << ptr->value << " ";
      printInfix(ptr->left);
      cout << ")";
    }
    else
      cout << ptr->value;
  }
  else
    cout << ptr->value;
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
  if (ptr->left != NULL || ptr->right != NULL) {
    printPostfix(ptr->right);
    cout << " ";
    printPostfix(ptr->left);
    cout << " ";
    cout << ptr->value;
  }
  else
    cout << ptr->value;
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
  if (stacklord.size()!=0 && stacklord.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
	printPostfix(stacklord.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
	printInfix(stacklord.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
	printPrefix(stacklord.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
  int total = 0;
  int r;
  int l;
  if (ptr->left == NULL)
    return atoi((ptr->value).c_str());
  else if (ptr->value == "+") {
    r = calculate(ptr->right);
    l = calculate(ptr->left);
    total += r + l;
  }
  else if (ptr->value == "-") {
    r = calculate(ptr->right);
    l = calculate(ptr->left);
    total += r - l;
  }
  else if (ptr->value == "*") {
    r = calculate(ptr->right);
    l = calculate(ptr->left);
    total += r * l;
  }
  else if (ptr->value == "/") {
    r = calculate(ptr->right);
    l = calculate(ptr->left);
    total += r / l;
  }
  return total;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    while (stacklord.size() != 0) {
      i += calculate(stacklord.top());
      stacklord.pop();
    }
    return i;
}
