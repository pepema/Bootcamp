#include "testshapes.hpp"

int main(){
  TestShapes t = TestShapes();
  t.TestTriangle(3,6);
  t.TestTriangle(-1,10);
  t.TestCircle(100);
  t.TestCircle(-100);
  t.TestRectangle(500,200);
  t.TestRectangle(-123,-234);
  t.TestSqaure(-10);
  t.TestCircle(1000000000000);
  return 0;
}