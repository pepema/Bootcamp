#include "pcapOpenner.h"
#include "convert.hpp"
#include <iostream>

int main(){
  pcapOpenner p;
  p.initPCAP("mycap.pcap");
  Packet_t packet = p.getPacket();
  for(int i=0;i<packet.data_len-1;i++){
    if(i==0) std::cout << "This is the destination: ";
    if(i==6) std::cout << "\nThis is the source: ";
    if(i==12) std::cout << "\nThis is the type: ";
    if(i<14){
      if(packet.data[i]==0) std::cout << "00 ";
      else if(packet.data[i]<15) std::cout << "0" << std::hex << (static_cast<int>(packet.data[i])) << " ";
      else std::cout << std::hex << (static_cast<int>(packet.data[i])) << " ";
    }
  }
  //long long int a = hex_to_oct(data);
  //std::cout << static_cast<int>(a);
  std::cout << "" << std::endl;
}