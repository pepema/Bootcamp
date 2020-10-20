#include "bonus.hpp"

using namespace std;

int main(){
  int users_choice, value_to_add, index, range_start, range_end;
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
      cout << "Please provide the following: (space separated)" << endl;
      cout << "What value do you want to add?" << endl;
      cout << "At what index? " << endl;
      cin >> value_to_add >> index;
      addItem(value_to_add);
    } else if (users_choice == 2){
        do{
          cout << "Please provide the following:" << endl;
          cout << "1. I want to add an index to remove" << endl;
          cout << "2. I want to add a range to remove" << endl;
          cin >> users_choice;
        } while(users_choice<1||users_choice>2);
        if(users_choice == 1){
          cout << "Please enter an index to remove" << endl;
          cin >> users_choice;
          removeItem(users_choice);
        } else /*the only other option is to remove a range..*/{
          cout << "Please enter a range to remove (space separated)" << endl;
          cin >> range_start >> range_end;
        }

      removeItem();
    } else if (users_choice == 3){
      printList();
    } else if (users_choice == 4){
      reverseList();
    }
  }
}

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
  } else {
    head = head->next;
  }
}
void removeItem(int index){
  
}
void printList(){
  Node* n = head;
  if(n == nullptr){
    cout << "The list is empty..."; 
  } else {
    while (n != nullptr) { 
      cout << n->data << " "; 
      n = n->next; 
    } 
  }
  cout << endl;
}

void reverseList(){

}