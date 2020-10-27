CXX = g++
NAME = makefileshapes
COMPARE = shapes/include/assignment_1.hpp
SRC = shapes/src/
INCLUDE = shapes/include/

all: main.o
	$(CXX) main.o libshape.so -o $(NAME).out

main.o: $(SRC)main.cpp libshape.so $(COMPARE)
	$(CXX) -c $(SRC)main.cpp -o main.o -I $(INCLUDE) -L.

libshape.so: shape.o 
	$(CXX) -c --shared -fPIC $(SRC)shape.cpp -o libshape.so -I $(INCLUDE)

shape.o: $(SRC)shape.cpp
	$(CXX) -c $(SRC)shape.cpp -o shape.o -I $(INCLUDE)

clean:
	rm libshape.so main.o makefileshapes.out shape.o