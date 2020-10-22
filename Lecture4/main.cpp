#include "polygon.hpp"
#include <iostream>

int main(){
  int size = 5;
  Shape * shapes[size]{
    new Triangle(5),
    new Rectangle(2,4),
    new Rectangle(2,4),
    new Square(5),
    new Circle(10)
  };
  int j=0;
  for(size_t i=0; i<size;i++){
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "Area: " << shapes[i]->area() << std::endl;
    std::cout << "Perimeter: " << shapes[i]->perimeter() << std::endl;
    //special case for comparing first shape
    if(i==0){
      j=i+1;
    } else {
      j=i-1;
    }
    if(*shapes[i]<*shapes[j]){
      std::cout << "This shape is smaller than the shape it's compared to" << std::endl;
    } else if (*shapes[i]>*shapes[j]){
      std::cout << "This shape is bigger than the shape it's compared to" << std::endl;
    } else if (*shapes[i]==*shapes[j]){
      std::cout << "This shape is equal in size to the shape it's compared to" << std::endl;
    } else {
      std::cout << "The laws of physics have been broken" << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
  }
  //Cleaning up
  for(size_t i =0; i<size;i++){
    delete shapes[i];
  }
  return 0;
}