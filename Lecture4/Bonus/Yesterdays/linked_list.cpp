#include "linked_list.hpp"

using namespace std;

void RecordList::createHead(Record record){
  head = new Node;
  head->record = record;
  head->next = nullptr;
  this->length++;
}
void RecordList::createLinkedHead(Record record){
  Node* tmp = head;
  head = new Node;
  head->record = record;
  head->next = tmp;
  this->length++;
}
void RecordList::addItem(Record record){
  //Check if this is head..
  if(head == nullptr){
    createHead(record);
  } else {
    Node* n = head;
    while(n->next != nullptr){
      n=n->next;
    }
    Node* newNode = new Node;
    n->next = newNode;
    newNode->record = record;
    newNode->next = nullptr;
    this->length++;
  }
}
void RecordList::addItem(Record record, int index){
  //Check if this is head..
  if(head == nullptr){
    createHead(record);
    return;
  }
  if(index == 0){
    createLinkedHead(record);
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
      newNode->record = record;
      newNode->next = tmp;
      this->length++;
      return;
    }
  counter++;
  n=n->next;
  }
  //Cover the case where we want to add to the last index
  if(n->next == nullptr && counter==index){
      this->addItem(record);
  } else {
    cout << endl;
    cout << "The index you chose was not valid" << endl;
    cout << "Try choosing something below or equal to " << counter << endl;
    cout << endl;
  }
}
void RecordList::removeItem(){
  if(head == nullptr){
    cout << "The list is empty..." << endl; 
  } else {
    Node* tmp = head;
    head = head->next;
    this->length--;
    delete tmp;
  }
}
void RecordList::removeItem(int index){
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
  //Cover the case where we want to remove the last record
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
void RecordList::removeItem(int range_start, int range_end){
  //loop backwards to not loose track of indexes
  for(int i=range_end;i>=range_start;i--){
    this->removeItem(i);
  }
}
void RecordList::removeAllItems(){
  this->removeItem(0,this->length-1);
}
void RecordList::printList(){
  cout << "---------------------This is the list--------------------" << endl;
  cout << endl;
  Node* n = head;
  if(n == nullptr){
    cout << "The list is empty..."; 
  } else {
    while (n != nullptr) { 
      n->record.PrintVisitInformation();
      n = n->next; 
    } 
  }
  cout << endl;
  cout << "---------------------------------------------------------" << endl;
  cout << endl;
}

void RecordList::reverseList(){
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