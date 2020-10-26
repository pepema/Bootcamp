#include "ring_buffer.hpp"
#include <iostream>
int main(){
  RingBuffer<uint32_t,10> circle;
  uint32_t x = 100 , y = 200;
  circle.put(x);
  circle.put(y);
  x = circle.get();
  std::cout << x << std::endl;
  x = circle.get();
  std::cout << x << std::endl;
}