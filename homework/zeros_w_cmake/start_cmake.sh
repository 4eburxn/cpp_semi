#!/bin/bash

cd ./build
cmake ..
chmod +x ../bin/zeroes.exe
make
make test