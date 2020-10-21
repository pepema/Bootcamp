#ifndef CAR_SHOP_HPP_
#define CAR_SHOP_HPP_
#include <iostream>
enum Parts{
  Engine,
  Hood,
  Trunk
};
enum Services{
  OilChange,
  FilterChange
};
enum PaymentMethods{
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
  Customer() = delete;
  Customer(Date DateVisited, Payment MethodUsed, Service ServicePerformed);
  Customer(Date DateVisited, Payment MethodUsed, Part PartChanged);
  Customer(Date DateVisited, Payment MethodUsed, Service ServicePerformed, Part PartChanged);
  Service ServicePerformed;
  Part PartChanged;
  Payment PaymentType;
  Date DateVisited;
  void PrintVisitInformation();
  ~Customer() = default;
};
#endif