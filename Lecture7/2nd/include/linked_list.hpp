#ifndef BONUS_HPP_
#define BONUS_HPP_
#include <iostream>
#include "car_shop.hpp"
class RecordList{
  public:
  typedef struct nod{
    Record record;
    struct nod* next;
  }Node;

  RecordList() = default;
  void createHead(Record record);
  void createLinkedHead(Record record);
  void addItem(Record record);
  void addItem(Record record,int index);
  void removeItem();
  void removeItem(int index);
  void removeItem(int range_start, int range_end);
  void removeAllItems();
  void printList();
  void reverseList();
  int length = 0;
  ~RecordList() = default;

  //Global variables
  Node* head = nullptr;
};
#endif