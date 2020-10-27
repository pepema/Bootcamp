#ifndef L5ASSIGN_1_HPP
#define L5ASSIGN_1_HPP

template<typename T>
void CompareShapes(T &_s1,T &_s2){
  if(_s1==_s2){
    std::cout << "Shapes compared are equal in size" << std::endl;
  } else if (_s1>_s2){
    std::cout << "Shape 1 is bigger" << std::endl;
  } else {
    std::cout << "Shape 2 is bigger" << std::endl;
  }
}

#endif