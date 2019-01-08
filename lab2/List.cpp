// Christian Kinzer
// cfk5ax
// 9/10/18
// List.cpp
// 9:30 AM lab

#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
using namespace std;

List::List() {
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
}

List::List(const List& source) {
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

List::~List() {
  ListItr itr(head->next);
  for (int i = 0; i < count; i++) {
    delete itr.current;
  }
  delete head;
  delete tail;
}

List& List::operator=(const List& source) {
  if (this == &source) {
    return *this;
  }
  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while(!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

bool List::isEmpty() const {
  if (count == 0)
    return true;
  else
    return false;
}

void List::makeEmpty() {
  ListItr itr(head->next);
  while (!itr.isPastEnd()) {
    remove(itr.retrieve());
    itr.moveForward();
  }
  count = 0;
}

ListItr List::first() {
  return ListItr(head->next);
}

ListItr List::last() {
  return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position) {
  ListNode* node = new ListNode();
  ListNode* front = position.current;
  ListNode* back = position.current->next;
  node->value = x;
  node->previous = front;
  node->next = back;
  back->previous = node;
  front->next = node;
  count++;
}

void List::insertBefore(int x, ListItr position) {
  ListNode* node = new ListNode();
  ListNode* back = position.current;
  ListNode* front = position.current->previous;
  node->value = x;
  node->previous = front;
  node->next = back;
  back->previous = node;
  front->next = node;
  count++;
}

void List::insertAtTail(int x) {
  ListNode* node = new ListNode();
  ListNode* prev = tail->previous;
  node->next = tail;
  node->previous = prev;
  prev->next = node;
  tail->previous = node;
  node->value = x;
  count++;
}

void List::remove(int x) {
  ListItr itr(head->next);
  for (int i = 0; i < count; i++) {
    if (itr.retrieve() == x) {
      ListNode* front = itr.current->previous;
      ListNode* back = itr.current->next;
      front->next = back;
      back->previous = front;
      delete itr.current;
      count--;
    }
    itr.moveForward();
  }
}

ListItr List::find(int x) {
  ListItr itr(head->next);
  for (int i = 0; i < count; i++) {
    if (itr.retrieve() == x) {
      return itr;
    }
    itr.moveForward();
  }
  return ListItr(tail);
}

int List::size() const {
  return count;
}
