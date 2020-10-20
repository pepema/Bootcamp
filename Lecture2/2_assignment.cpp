#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};

//global variable
Node* head = nullptr;

void addItem(int value_to_add){
  //Check if this is head..
  if(head == nullptr){
    head = new Node;
    head->data = value_to_add;
    head->next = nullptr;
  } else {
    Node* n = head;
    while(n->next != nullptr){
      n=n->next;
    }
    cout << "found tail" << endl;
    Node* newNode = new Node;
    n->next = newNode;
    newNode->data = value_to_add;
    newNode->next = nullptr;
  }
  
}
void removeItem(){
  if(head == nullptr){
    cout << "The list is empty..." << endl; 
  }
  else{
    head = head->next;
  }
}
void printList(){
  Node* n = head;
  if(n == nullptr){
    cout << "The list is empty..."; 
  }
  else{
    while (n != nullptr) { 
      cout << n->data << " "; 
      n = n->next; 
    } 
  }
  cout << endl;
}

int main(){
  int users_choice, value_to_add;
  while(true){
    do{
      cout << "What do you want to do? choose one of the following numbers:" << endl;
      cout << "1. Add items to the end of the list" << endl;
      cout << "2. Remove items from the front of the list" << endl;
      cout << "3. Print the list" << endl;
      cin >> users_choice;
    }
    while(users_choice<1 || users_choice > 3);

    if(users_choice == 1){
      cout << "What value do you want to add?" << endl;
      cin >> value_to_add;
      addItem(value_to_add);
    }
    else if(users_choice == 2){
      removeItem();
    }
    else if(users_choice == 3){
      printList();
    }
  }
}
