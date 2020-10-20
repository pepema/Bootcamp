#ifndef BONUS_HPP_
#define BONUS_HPP_

#include <iostream>
typedef struct nod{
  int data;
  struct nod* next;
}Node;

void createHead(int value);
void createLinkedHead(int value);
void addItem(int value_to_add);
void addItem(int value_to_add,int index);
void removeItem();
void removeItem(int index);
void removeItem(int range_start, int range_end);
void printList();
void reverseList();

//Global variables
Node* head = nullptr;

#endif