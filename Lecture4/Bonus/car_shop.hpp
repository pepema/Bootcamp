#ifndef CAR_SHOP_HPP_
#define CAR_SHOP_HPP_
#include <iostream>
enum class Parts{
  Engine,
  Hood,
  Trunk
};
enum class Services{
  OilChange,
  FilterChange
};
enum class PaymentMethods{
  Card,
  Cash,
  Phone
};

class Part{
  public:
  Part() = default;
  Part(Parts SpecificPart);
  Parts SpecificPart;
  void PrintPart();
  ~Part() = default;
};
class Service{
  public:
  Service() = default;
  Service(Services Service);
  Services SpecificService;
  void PrintService();
  ~Service() = default;
};
class Payment{
  public:
  Payment() = default;
  Payment(int Amount, PaymentMethods Method);
  int Amount;
  PaymentMethods SpecificMethod;
  void PrintPayment();
  ~Payment() = default;
};
class Date{
  public:
  Date() = default;
  Date(int year, int month, int day);
  int year,month,day;
  void PrintDate();
  ~Date() = default;

};
class Customer{
  public:
  Customer() = default;
  Customer(std::string name);
  std::string name;
  int identification;
  void PrintCustomerName();
  ~Customer() = default;
};

class Record{
  public:
  Record() = default;
  Record(Date DateVisited, Payment MethodUsed, Service ServicePerformed, Customer CustomerName);
  Record(Date DateVisited, Payment MethodUsed, Part PartChanged, Customer CustomerName);
  Record(Date DateVisited, Payment MethodUsed, Service ServicePerformed, Part PartChanged, Customer CustomerName);
  Service ServicePerformed;
  Part PartChanged;
  Payment PaymentType;
  Date DateVisited;
  Customer CustomerName;
  void PrintVisitInformation();
  ~Record() = default;
};
#endif