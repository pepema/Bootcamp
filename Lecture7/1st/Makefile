CXX = g++
NAME = makefileshapes
COMPARE = shapes/include/assignment_1.hpp
SRC = shapes/src/
INCLUDE = shapes/include/

all: $(SRC)main.cpp libshape.so $(COMPARE)
	$(CXX) $(SRC)main.cpp -o main.out -I $(INCLUDE) -L. -lshape

libshape.so: shape.o 
	$(CXX) -c --shared -fPIC $(SRC)shape.cpp -o libshape.so -I $(INCLUDE) 

shape.o: $(SRC)shape.cpp
	$(CXX) -c $(SRC)shape.cpp -o shape.o -I $(INCLUDE)

clean:
	rm libshape.so main.out shape.o