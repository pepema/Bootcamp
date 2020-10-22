#include "linked_list.hpp"

using namespace std;

void LinkedList::createHead(Record customer){
  head = new Node;
  head->customer = customer;
  head->next = nullptr;
  this->length++;
}
void LinkedList::createLinkedHead(Record customer){
  Node* tmp = head;
  head = new Node;
  head->customer = customer;
  head->next = tmp;
  this->length++;
}
void LinkedList::addItem(Record customer){
  //Check if this is head..
  if(head == nullptr){
    createHead(customer);
  } else {
    Node* n = head;
    while(n->next != nullptr){
      n=n->next;
    }
    Node* newNode = new Node;
    n->next = newNode;
    newNode->customer = customer;
    newNode->next = nullptr;
    this->length++;
  }
}
void LinkedList::addItem(Record customer, int index){
  //Check if this is head..
  if(head == nullptr){
    createHead(customer);
    return;
  }
  if(index == 0){
    createLinkedHead(customer);
    return;
  }
  Node* n = head;
  //start at 1 since we have special case for index 0
  int counter = 1;
  while(n->next != nullptr){
    if(counter == index){
      Node* newNode = new Node;
      Node* tmp = n->next;
      n->next = newNode;
      newNode->customer = customer;
      newNode->next = tmp;
      this->length++;
      return;
    }
  counter++;
  n=n->next;
  }
  //Cover the case where we want to add to the last index
  if(n->next == nullptr && counter==index){
      this->addItem(customer);
  } else {
    cout << endl;
    cout << "The index you chose was not valid" << endl;
    cout << "Try choosing something below or equal to " << counter << endl;
    cout << endl;
  }
}
void LinkedList::removeItem(){
  if(head == nullptr){
    cout << "The list is empty..." << endl; 
  } else {
    Node* tmp = head;
    head = head->next;
    this->length--;
    delete tmp;
  }
}
void LinkedList::removeItem(int index){
  if(index == 0){
    this->removeItem();
    return;
  }
  Node* n = head;
  Node* prev;
  int counter = 0;
  while(n->next != nullptr){
    if(counter == index){
      prev->next = n->next;
      this->length--;
      delete n;
      return;
    }
    counter++;
    prev = n;
    n=n->next;
  }
  //Cover the case where we want to remove the last customer
  if(n->next == nullptr && counter==index){
      prev->next = n->next;
      this->length--;
      delete n;
      return;
  } else {
      cout << "Your provided index range could not be found.." << endl;
      cout << "Try choosing something below " << counter << endl;
  }
}
void LinkedList::removeItem(int range_start, int range_end){
  //loop backwards to not loose track of indexes
  for(int i=range_end;i>=range_start;i--){
    this->removeItem(i);
  }
}
void LinkedList::removeAllItems(){
  this->removeItem(0,this->length-1);
}
void LinkedList::printList(){
  cout << "---------------------This is the list--------------------" << endl;
  cout << endl;
  Node* n = head;
  if(n == nullptr){
    cout << "The list is empty..."; 
  } else {
    while (n != nullptr) { 
      n->customer.PrintVisitInformation();
      n = n->next; 
    } 
  }
  cout << endl;
  cout << "---------------------------------------------------------" << endl;
  cout << endl;
}

void LinkedList::reverseList(){
  Node* current = head;
  Node *prev = nullptr, *next = nullptr; 
  while (current != nullptr){ 
    // Store next
    next = current->next; 
    // Reverse current node's pointer 
    current->next = prev; 
    // Move pointers one position ahead. 
    prev = current; 
    current = next; 
  } 
  head = prev; 
}