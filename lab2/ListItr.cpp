// Christian Kinzer
// cfk5ax
// 9/10/18
// ListItr.cpp
// 9:30 AM lab

#include <iostream>
#include "ListItr.h"
#include "List.h"
#include "ListNode.h"
using namespace std;

ListItr::ListItr() {
  current = NULL;
}

ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

bool ListItr::isPastEnd() const {
  if (current->next == NULL) {
    return true;
  }
  else
    return false;
}

bool ListItr::isPastBeginning() const {
  if (current->previous == NULL) {
    return true;
  }
  else
    return false;
}

void ListItr::moveForward() {
  if (!isPastEnd()) {
    current = current->next;
  }
}

void ListItr::moveBackward() {
  if (!isPastBeginning()) {
    current = current->previous;
  }
}

int ListItr::retrieve() const {
  return current->value;
}

void printList(List& theList, bool forward) {
  if (forward) {
    ListItr itr = theList.first();
    while (!itr.isPastEnd()) {
      cout << itr.retrieve() << " ";
      itr.moveForward();
    }
  }
  else {
    ListItr itr = theList.last();
    while (!itr.isPastBeginning()) {
      cout << itr.retrieve() << " ";
      itr.moveBackward();
    }
  }
}
