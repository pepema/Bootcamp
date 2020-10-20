#ifndef BONUS_HPP_
#define BONUS_HPP_

#include <iostream>
typedef struct nod{
  int data;
  int index;
  struct nod* next;
}Node;

void addItem(int value_to_add);
void addItem(int value_to_add,int index);
void removeItem();
void removeItem(int index);
void printList();
void reverseList();

//Global variables
Node* head = nullptr;

#endif