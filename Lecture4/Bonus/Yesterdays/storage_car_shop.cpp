#include "linked_list.hpp"

int main(){
  Part part_;
  Date date_;
  Payment payment_;
  Service service_;
  Customer customer_;
  LinkedList list_;

  part_ = Part(Parts::Trunk);
  date_ = Date(94,11,14);
  payment_ = Payment(15000,PaymentMethods::Phone);
  customer_ = Customer("frank");
  Record one = Record(date_,payment_,part_,customer_);

  part_ = Part(Parts::Engine);
  date_ = Date(93,05,02);
  payment_ = Payment(1410065407,PaymentMethods::Cash);
  customer_ = Customer("ludi");
  Record two = Record(date_,payment_,part_,customer_);

  service_ = Service(Services::OilChange);
  date_ = Date(20,10,21);
  payment_ = Payment(2,PaymentMethods::Card);
  customer_ = Customer("boss");
  Record three = Record(date_,payment_,service_,customer_);

  service_ = Service(Services::FilterChange);
  part_ = Part(Parts::Hood);
  date_ = Date(87,04,13);
  payment_ = Payment(666,PaymentMethods::Card);
  customer_ = Customer("nisse");
  Record four = Record(date_,payment_,service_,part_,customer_);

  /*list_.addItem(frank_);
  list_.addItem(nisse_);*/
  list_.addItem(one);
  list_.addItem(two);
  list_.addItem(three);
  /*list_.addItem(ludi_);
  list_.addItem(ludi_);
  list_.addItem(frank_);*/
  list_.addItem(four,3);
  list_.removeItem(0,2);
  //list_.printList();
  //list_.addItem(ludi_,0);
  /*
  list_.removeItem(0,7);
  list_.printList();
  list_.removeItem();
  list_.printList();
  list_.removeItem();
  list_.printList();
  */
  list_.printList();
  if(list_.length > 0){
    list_.removeAllItems();
  }
  list_.printList();
}