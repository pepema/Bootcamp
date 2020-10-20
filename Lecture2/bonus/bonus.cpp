#include "bonus.hpp"

using namespace std;

int main(){
  int users_choice, value_to_add, index, range_start, range_end;
  //for testing i want to add some values to the list every time..
  for(int i=0;i<10;i++){
    addItem(i);
  }
  while(true){
    do{
      cout << "What do you want to do? choose one of the following numbers:" << endl;
      cout << "1. Add items" << endl;
      cout << "2. Remove items" << endl;
      cout << "3. Print the list" << endl;
      cout << "4. Reverse the list" << endl;
      cin >> users_choice;
    }
    while(users_choice<1 || users_choice > 3);

    if(users_choice == 1){
      do{
        cout << "Please provide the following: (space separated)" << endl;
        cout << "1. I want to provide an index" << endl;
        cout << "<any other>. I don't care where the value is added" << endl;
        cin >> users_choice;
      } while(users_choice<1||users_choice>2);
      
      if(users_choice == 1){
        cout << "Please provide the following: (space separated)" << endl;
        cout << "What value do you want to add?" << endl;
        cout << "At what index? " << endl;
        cin >> value_to_add >> index;
        addItem(value_to_add,index);
      } else {
        cout << "What value do you want to add?" << endl;
        cin >> value_to_add;
        addItem(value_to_add);
      }
    } 
    else if (users_choice == 2){
      do{
        cout << "Please provide the following:" << endl;
        cout << "1. I want to choose an index to remove" << endl;
        cout << "2. I want to choose a range to remove" << endl;
        cout << "<any other>. I don't care, just remove something" << endl;
        cin >> users_choice;
      } while(users_choice<1||users_choice>2);
      if(users_choice == 1){
        cout << "Please enter an index to remove" << endl;
        cin >> users_choice;
        removeItem(users_choice);
      } else if(users_choice == 2){
        cout << "Please enter a range to remove (space separated)" << endl;
        cin >> range_start >> range_end;
        removeItem(range_start,range_end);
      } else {
          removeItem();
      }

    } 
    else if (users_choice == 3){
      printList();
    } 
    else if (users_choice == 4){
      reverseList();
    }
  }
}
void createHead(int value){
  head = new Node;
  head->data = value;
  head->next = nullptr;
}
void createLinkedHead(int value){
  Node* tmp = head;
  head = new Node;
  head->data = value;
  head->next = tmp;
}
void addItem(int value_to_add){
  //Check if this is head..
  if(head == nullptr){
    createHead(value_to_add);
  } else {
    Node* n = head;
    while(n->next != nullptr){
      n=n->next;
    }
    Node* newNode = new Node;
    n->next = newNode;
    newNode->data = value_to_add;
    newNode->next = nullptr;
  }
}
void addItem(int value_to_add,int index){
  //Check if this is head..
  if(head == nullptr){
    createHead(value_to_add);
  } else {
    Node* n = head;
    int counter = 0;
    if(index == 0){
      createLinkedHead(value_to_add);
    } 
    else {
      while(n->next != nullptr){
        if(counter == index){
          Node* newNode = new Node;
          Node* tmp = n->next;
          n->next = newNode;
          newNode->data = value_to_add;
          newNode->next = tmp;
        }
        counter++;
        n=n->next;
      }
    }
    cout << "The index you chose was not valid" << endl;
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
  Node* n = head;
  Node* prev;
  int counter = 0;
  while(n->next != nullptr){
    if(counter == index){
      prev->next = n->next;
      break;
    }
    counter++;
    prev = n;
    n=n->next;
  }
  cout << "Your provided index could not be found.." << endl;
}
void removeItem(int range_start, int range_end){

}
void printList(){
  cout << "---------------------This is the list--------------------" << endl;
  cout << endl;
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
  cout << "---------------------------------------------------------" << endl;
  cout << endl;
}

void reverseList(){

}