#!/bin/bash
git clone git@github.com:pepema/Bootcamp.git
cd Bootcamp/Lecture7/1st 
make
export LD_LIBRARY_PATH=.
./main.out