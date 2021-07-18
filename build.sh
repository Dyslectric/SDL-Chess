#!/bin/bash
rm bin/release
rm -rf bin/assets
g++ -c src/*.cpp -m64 -Wall -I include
g++ -c src/*/*.cpp -m64 -Wall -I include
g++ *.o -l SDL2 -l SDL2_image -o bin/release
cp -rf assets bin/assets
rm *.o
bin/release
