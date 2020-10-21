#ifndef BONUS_HPP_
#define BONUS_HPP_
#include <iostream>
#include "../car_shop.hpp"
class LinkedList{
  public:
  typedef struct nod{
    Customer customer;
    struct nod* next;
  }Node;

  LinkedList() = default;
  void createHead(Customer customer);
  void createLinkedHead(Customer customer);
  void addItem(Customer customer);
  void addItem(Customer customer,int index);
  void removeItem();
  void removeItem(int index);
  void removeItem(int range_start, int range_end);
  void removeAllItems();
  void printList();
  void reverseList();
  int length = 0;
  ~LinkedList() = default;

  //Global variables
  Node* head = nullptr;
};
#endif