#include "car_shop.hpp"
int main(){
  Part part_;
  Date date_;
  Payment payment_;
  Service service_;

  part_ = Part(Parts::Trunk);
  date_ = Date(94,11,14);
  payment_ = Payment(15000,PaymentMethods::Phone);
  Customer frank_ = Customer(date_,payment_,part_);

  part_ = Part(Parts::Engine);
  date_ = Date(93,05,02);
  payment_ = Payment(1410065407,PaymentMethods::Cash);
  Customer ludi_ = Customer(date_,payment_,part_);

  service_ = Service(Services::OilChange);
  date_ = Date(20,10,21);
  payment_ = Payment(2,PaymentMethods::Card);
  Customer boss_ = Customer(date_,payment_,service_);

  service_ = Service(Services::FilterChange);
  part_ = Part(Parts::Hood);
  date_ = Date(87,04,13);
  payment_ = Payment(666,PaymentMethods::Card);
  Customer nisse_ = Customer(date_,payment_,service_,part_);

  frank_.PrintVisitInformation();
  std::cout << "--------------------------------------" << std::endl;
  ludi_.PrintVisitInformation();
  std::cout << "--------------------------------------" << std::endl;
  boss_.PrintVisitInformation();
  std::cout << "--------------------------------------" << std::endl;
  nisse_.PrintVisitInformation();

}