#!/bin/bash
rm ../bin/zeroes.exe
mkdir build
cd ./build
cmake ..
chmod +x ../bin/zeroes.exe
make
make test