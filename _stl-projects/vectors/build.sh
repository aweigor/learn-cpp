#!/bin/bash
# compile
g++ -std=c++17 $1 -o app
# execute
./app
rm app