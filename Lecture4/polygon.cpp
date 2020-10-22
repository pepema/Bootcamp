#include "polygon.hpp"
#include <iostream>
bool Shape::operator==(Shape& shape){
  if(this->area() == shape.area()){
    if(this->perimeter() == shape.perimeter()){
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}
bool Shape::operator<(Shape& shape){
  if(this->area()==shape.area()){
    if(this->perimeter() < shape.perimeter()){
      return true;
    } else {
      return false;
    }
  } else if(this->area() < shape.area()){
    return true;
  } else {
    return false;
  }
}
bool Shape::operator>(Shape& shape){
  if(this->area()==shape.area()){
    if(this->perimeter() > shape.perimeter()){
      return true;
    } else {
      return false;
    }
  } else if(this->area() > shape.area()){
    return true;
  } else {
    return false;
  }
}
Triangle::Triangle(int side){
  this->side = side;
}
int Triangle::perimeter(){
  return this->side*3;
}
int Triangle::area(){
  return (sqrt(3)/2)*this->side;
}
Rectangle::Rectangle(int height, int length){
  this->height = height;
  this->length = length;
}
int Rectangle::perimeter(){
  return this->height*2+this->length*2;
}
int Rectangle::area(){
  return this->height*this->length;
}
Square::Square(int side){
  this->side = side;
}
int Square::perimeter(){
  return this->side*4;
}
int Square::area(){
  return pow(this->side,2);
}
Circle::Circle(int diameter){
  this->diameter=diameter;
}
int Circle::perimeter(){
  return M_PI*this->diameter;
}
int Circle::area(){
  return M_PI*pow((this->diameter/2),2);
}