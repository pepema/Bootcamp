#include "shape.h"
#include "assignment_1.hpp"

class TestShapes{
public:
  TestShapes() = default;
  void TestTriangle(const int &_w, const int &_h);
  void TestCircle(const int &_r);
  void TestRectangle(const int &_w,const int &_h);
  void TestSqaure(const int &_s);
  ~TestShapes() = default;
private:
  int GetPerimiter(const Shape& s){return s.Perimiter;}
  int GetArea(const Shape& s){return s.Area;}
};

void TestShapes::TestTriangle(const int &_w, const int &_h){
  std::cout << "-------Testing Triangle with width: " << _w << " and height: " << _h << "-------" << std::endl;
  int p = this->GetPerimiter(Triangle(_w,_h));
  if(p==_w*3 && p>0){
    std::cout << "Perimeter test PASS" << std::endl;
  } else if( _w<=0 || _h<=0){
    if(p==0){
      std::cout << "Perimeter test PASS" << std::endl;
    } else {
      std::cout << "Perimeter test FAILED" << std::endl;
    }
  } else {
    std::cout << "Perimeter test FAILED" << std::endl;
  }
  int a = this->GetArea(Triangle(_w,_h));
  if(a==_h*_w/2 && a>0){
    std::cout << "Area test PASS" << std::endl;
  } else if( _w<=0 || _h<=0){
    if(a==0){
      std::cout << "Area test PASS" << std::endl;
    } else {
      std::cout << "Area test FAILED" << std::endl;
    }
  } else {
    std::cout << "Area test FAILED" << std::endl;
  }
}

void TestShapes::TestCircle(const int &_r){
  std::cout << "-------Testing Circle with radius: " << _r <<  "-------" << std::endl;
  int p = this->GetPerimiter(Circle(_r));
  if(p==_r*3*2 && p>0){
    std::cout << "Perimeter test PASS" << std::endl;
  } else if( _r<=0){
    if(p==0){
      std::cout << "Perimeter test PASS" << std::endl;
    } else {
      std::cout << "Perimeter test FAILED" << std::endl;
    }
  } else {
    std::cout << "Perimeter test FAILED" << std::endl;
  }
  int a = this->GetArea(Circle(_r));
  if( _r<=0){
    if(a==0){
      std::cout << "Area test PASS" << std::endl;
    } else {
      std::cout << "Area test FAILED" << std::endl;
    }
  } else {
    if(a==std::pow(_r,2) && a>0){
      std::cout << "Area test PASS" << std::endl;
    } else {
      std::cout << "Area test FAILED" << std::endl;
    }
  }
}
void TestShapes::TestRectangle(const int &_w,const int &_h){
  std::cout << "-------Testing Rectangle with radius: " << _w << " and height: " << _h << "-------" << std::endl;
  int p = this->GetPerimiter(Rectangle(_h,_w));
  if( _w<=0 || _h<=0){
    if(p==0){
      std::cout << "Perimeter test PASS" << std::endl;
    } else {
      std::cout << "Perimeter test FAILED" << std::endl;
    }
  } else {
    if(p==(2*_w)+(2*_h) && p>0){
      std::cout << "Perimeter test PASS" << std::endl;
    } else {
      std::cout << "Perimeter test FAILED" << std::endl;
    }
  }

  int a = this->GetArea(Rectangle(_h,_w));
  if( _w<=0 || _h<=0){
    if(a==0){
      std::cout << "Area test PASS" << std::endl;
    } else {
      std::cout << "Area test FAILED" << std::endl;
    }
  } else {
    if(a==_w*_h && a>0){
      std::cout << "Area test PASS" << std::endl;
    } else {
      std::cout << "Area test FAILED" << std::endl;
    }
  }
}


void TestShapes::TestSqaure(const int &_s){
  std::cout << "-------Testing Sqaure with side: " << _s <<  "-------" << std::endl;
  int p = this->GetPerimiter(Square(_s));
  if(p==_s*4 && p>0){
    std::cout << "Perimeter test PASS" << std::endl;
  } else if( _s<=0){
    if(p==0){
      std::cout << "Perimeter test PASS" << std::endl;
    } else {
      std::cout << "Perimeter test FAILED" << std::endl;
    }
  } else {
    std::cout << "Perimeter test FAILED" << std::endl;
  }
  int a = this->GetArea(Square(_s));
  if( _s<=0){
    if(a==0){
      std::cout << "Area test PASS" << std::endl;
    } else {
      std::cout << "Area test FAILED" << std::endl;
    }
  } else {
    if(a==std::pow(_s,2) && a>0){
      std::cout << "Area test PASS" << std::endl;
    } else {
      std::cout << "Area test FAILED" << std::endl;
    }
  }
}