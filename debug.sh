#!/bin/bash
rm bin/debug
g++ -c src/*.cpp -m64 -g -Wall -I include
g++ -c src/*/*.cpp -m64 -g -Wall -I include
g++ *.o -l SDL2 -l SDL2_image -o bin/debug
rm *.o
bin/debug
