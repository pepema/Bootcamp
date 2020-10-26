#include <iostream>
#include <bitset>

struct CarStatus {
  unsigned  lights:3;
  unsigned  doors:4;
  unsigned  windows:4;
  unsigned  seat_belts:4;           
};

struct DoorStatus {
  unsigned driver:1;
  unsigned passenger:1;
  unsigned driver_rear:1;
  unsigned passenger_rear:1;
};

struct WindowStatus {
  unsigned driver:1;
  unsigned passenger:1;
  unsigned driver_rear:1;
  unsigned passenger_rear:1;
};

struct SeatBeltStatus {
  unsigned driver:1;
  unsigned passenger:1;
  unsigned driver_rear:1;
  unsigned passenger_rear:1;
};

struct LightStatus {
  unsigned driver_cabin:1;
  unsigned passenger_cabin:1;
  unsigned rear_cabin:1;
};

struct CarStatusTwo {
  DoorStatus* DS;
  WindowStatus* WS;
  SeatBeltStatus* SBS;
  LightStatus* LS;         
};

void PrintCarStatus(CarStatusTwo& CST){
  //Lights
  std::cout << "------------Light status of the vehicle------------" << std::endl;
  std::cout << "Driver cabin light status: " << CST.LS->driver_cabin << std::endl;
  std::cout << "Passenger cabin light status: " << CST.LS->passenger_cabin << std::endl;
  std::cout << "Rear cabin light status: " << CST.LS->rear_cabin << std::endl;
  //Doors
  std::cout << "------------Door status of the vehicle------------" << std::endl;
  std::cout << "Driver door status: " << CST.DS->driver << std::endl;
  std::cout << "Passenger door status: " << CST.DS->passenger << std::endl;
  std::cout << "Rear driver door status: " << CST.DS->driver_rear << std::endl;
  std::cout << "Rear passenger door status: " << CST.DS->passenger_rear << std::endl;
  //Windows
  std::cout << "------------Window status of the vehicle------------" << std::endl;
  std::cout << "Window driver status: " << CST.WS->driver << std::endl;
  std::cout << "Window passenger status: " << CST.WS->passenger << std::endl;
  std::cout << "Window driver rear status: " << CST.WS->driver_rear << std::endl;
  std::cout << "Window passenger rear status: " << CST.WS->passenger_rear << std::endl;
  //Seat belts
  std::cout << "------------Seat belt status of the vehicle------------" << std::endl;
  std::cout << "Seat belt driver status: " << CST.SBS->driver << std::endl;
  std::cout << "Seat belt passenger status: " << CST.SBS->passenger << std::endl;
  std::cout << "Seat belt driver rear status: " << CST.SBS->driver_rear << std::endl;
  std::cout << "Seat belt passenger rear status: " << CST.SBS->passenger_rear << std::endl;
}

void ReadInformation(const uint16_t& info){
  uint8_t l_ = info & 0b111, d_ = info >> 3 & 0b1111, w_ = info >> 7 & 0b1111, s_ = info >> 11 & 0b1111;
  LightStatus *l = reinterpret_cast<LightStatus*>(&l_);
  DoorStatus *d = reinterpret_cast<DoorStatus*>(&d_);
  WindowStatus *w = reinterpret_cast<WindowStatus*>(&w_);
  SeatBeltStatus *s = reinterpret_cast<SeatBeltStatus*>(&s_);

  CarStatusTwo status = {d,w,s,l};

  /*
  //Lights
  status.LS.driver_cabin = info & 1;
  status.LS.passenger_cabin = (info & 1 << 1) >> 1;
  status.LS.rear_cabin = (info & 1 << 2) >> 2;

  //Doors
  status.DS.driver = (info & 1 << 2) >> 2;
  */
  PrintCarStatus(status);

}

int main(){
  uint16_t car_info = 0b1011101001011011;
  ReadInformation(car_info);


}