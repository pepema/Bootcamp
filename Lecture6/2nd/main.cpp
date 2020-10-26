#include <iostream>
#include <bitset>
#include <array>

template<typename T>
uint16_t ConvertDistance(const T &d){
  uint16_t ret;
  if((d/150) > 0b111){
    ret = 0b111;
  } else {
    ret = d/150;
  }
  return ret;
}
template<typename T>
uint16_t ConvertSpeed(const T &s){
  uint16_t ret;
  if((s/20) > 0xF){
    ret = 0xF;
  } else {
    ret = s/20;
  }
  return ret;
}
template <typename T1, typename T2>
uint16_t Encode(T1 speed, T2 d_front, T2 d_rear, T2 d_right, T2 d_left){ 
  uint16_t encoded_info = 0;
  std::array<T2,4> distances = { d_left, d_right, d_rear, d_front};
  for(int i=0; i<4; i++){
    encoded_info += ConvertDistance(distances[i]) << (i*3);
    }
  encoded_info += ConvertSpeed(speed) << 12;
  return encoded_info;
}
void DetectCrash(uint16_t info){
  std::bitset<4> sides;
  for(int i=0; i<4; i++){
    if((info >> (i*3) & 0b111) == 0){
      sides[i] = 1;
    } else {
      sides[i] = 0;
    }
  }
  //if vehicle has speed
  if((info >> 12) & 0b1111){
    if(sides[0]){
      std::cout << "Crash detected from the left" << std::endl;
    }
    if(sides[1]){
      std::cout << "Crash detected from the right" << std::endl;
    }
    if(sides[2]){
      std::cout << "Crash detected from the rear" << std::endl;
    }
    if(sides[3]){
      std::cout << "Crash detected from the front" << std::endl;
    }
  }
}

int main(){
  int dfr = 150*2, dre = 150*3, dri = 150*5, drl = 150*3, spd = 20*12;
  uint16_t encoded = Encode(spd,dfr,dre,dri,drl);
  DetectCrash(encoded);
}