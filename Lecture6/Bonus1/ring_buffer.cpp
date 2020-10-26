#include "ring_buffer.hpp"
#include <iostream>
int main(){
  const size_t size = 10;
  RingBuffer<uint32_t,size> circle;
  for(int i=1;i<size+1;i++){
    circle.put(i);
  }
  for(int i=0;i<size+2;i++){
    std::cout << circle.get() << std::endl;
  }
}