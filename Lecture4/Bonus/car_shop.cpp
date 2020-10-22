#include "car_shop.hpp"

Part::Part(Parts SpecificPart){
  this->SpecificPart = SpecificPart;
}

void Part::PrintPart(){
  switch (this->SpecificPart)
  {
  case Parts::Engine:
    std::cout << "During this visit an engine was swapped" << std::endl;
    break;
  case Parts::Hood:
    std::cout << "During this visit the hood was changed" << std::endl;
    break;
  case Parts::Trunk:
    std::cout << "During this visit the trunk was fixed" << std::endl;
    break;
  default:
    std::cout << "No parts was changed during this visit" << std::endl;
    break;
  }
}

Service::Service(Services SpecificService){
  this->SpecificService = SpecificService;
}

void Service::PrintService(){
  switch (this->SpecificService)
  {
  case Services::OilChange:
    std::cout << "During this visit an oil change was done" << std::endl;
    break;
  case Services::FilterChange:
    std::cout << "During this visit a filter change was done" << std::endl;
    break;
  default:
    std::cout << "No service was performed during this visit" << std::endl;
    break;
  }
}

Payment::Payment(int Amount, PaymentMethods SpecificMethod){
  this->Amount = Amount;
  this->SpecificMethod = SpecificMethod;
}

void Payment::PrintPayment(){
  switch (this->SpecificMethod)
  {
  case PaymentMethods::Card:
    std::cout << this->Amount << " kr was payed with card" << std::endl;
    break;
  case PaymentMethods::Cash:
    std::cout << this->Amount << " kr was payed with cash" << std::endl;
    break;
  case PaymentMethods::Phone:
    std::cout << this->Amount << " kr was payed with phone" << std::endl;
    break;
  
  default:
    std::cout << "Specified payment method was not available" << std::endl;
    break;
  }
}

Date::Date(int year, int month, int day){
  this->year = year;
  this->month = month;
  this->day = day;
}
void Date::PrintDate(){
  std::cout << "This is the date of the visit:";
  std::cout << " Year: " << this->year 
            << " Month: "<< this->month 
            << " Day: "  << this->day  << std::endl;
}

Customer::Customer(std::string name){
  this->name = name;
  this->identification = rand()%99999;
}

void Customer::PrintCustomerName(){
  std::cout << "Customer: " << this->name << " with id: " << this->identification << std::endl;
}

//Case where only a service was performed
Record::Record(Date DateVisited, Payment MethodUsed, Service ServicePerformed, Customer CustomerName){
  this->DateVisited = DateVisited;
  this->PaymentType = MethodUsed;
  this->ServicePerformed = ServicePerformed;
  this->CustomerName = CustomerName;
}

//Case where only a Part was changed
Record::Record(Date DateVisited, Payment MethodUsed, Part PartChanged, Customer CustomerName){
  this->DateVisited = DateVisited;
  this->PaymentType = MethodUsed;
  this->PartChanged = PartChanged;
  this->CustomerName = CustomerName;
}
//Case where customer changes part and does service
Record::Record(Date DateVisited, Payment MethodUsed, Service ServicePerformed, Part PartChanged, Customer CustomerName){
  this->DateVisited = DateVisited;
  this->PaymentType = MethodUsed;
  this->PartChanged = PartChanged;
  this->ServicePerformed = ServicePerformed;
  this->CustomerName = CustomerName;
}
void Record::PrintVisitInformation(){
  std::cout << "----------------------------------------------------" << std::endl;
  this->CustomerName.PrintCustomerName();
  this->DateVisited.PrintDate();
  this->PartChanged.PrintPart();
  this->PaymentType.PrintPayment();
  this->ServicePerformed.PrintService();
  std::cout << "----------------------------------------------------" << std::endl;
}
