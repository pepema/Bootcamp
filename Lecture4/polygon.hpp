#ifndef POLYGON_HPP_
#define POLYGON_HPP_
#include<math.h>
#include<cmath>

class Shape{
protected:
  int height,length;
public:
  Shape() = default;
  Shape(int height, int length);
  virtual int perimeter() = 0;
  virtual int area() = 0;
  bool operator<(Shape& shape);
  bool operator>(Shape& shape);
  bool operator==(Shape& shape);
  ~Shape() = default;
};
class Triangle : public Shape {
private:
  int side;
public:
  Triangle(int side);
  int perimeter() override;
  int area() override;
  ~Triangle();
};
class Rectangle : public Shape {
public:
  Rectangle(int height, int length);
  int perimeter() override;
  int area() override;
  ~Rectangle();
};
class Square : public Shape {
private:
  int side;
public:
  Square(int side);
  int perimeter() override;
  int area() override;
  ~Square();
};
class Circle : public Shape{
private: 
  int diameter;
public:
  Circle(int diameter);
  int perimeter() override;
  int area() override;
  ~Circle();
};

#endif