// Christian Kinzer
// cfk5ax
// 9/20/18
// stack.cpp

#include <iostream>
#include "stackNode.h"
#include "stack.h"
using namespace std;

stack::stack() { // default constructor
  head = new stackNode();
  tail = new stackNode();
  head->next = tail;
  count = 0;
}

stack::~stack() { // destructor

}

bool stack::empty() {
  if (count == 0)
    return true;
  else
    return false;
}

void stack::push(int x)  {
  stackNode* node = new stackNode();
  stackNode* oldhead = head->next;
  head->next = node;
  node->next = oldhead;
  node->value = x;
  count ++;
}

void stack::pop() {
  stackNode* oldhead = head->next;
  stackNode* newhead = head->next->next;
  head->next = newhead;
  delete oldhead;
  count --;
}

int stack::top() {
  return head->next->value;
}
