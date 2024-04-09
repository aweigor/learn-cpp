#!/bin/bash
# compile
g++ -std=c++11 $1 -o app
# execute
./app
rm app