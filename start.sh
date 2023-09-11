#!/bin/bash

g++ -Og -Wall -Wextra -pedantic -Ilib -o bin/$1 $1 && bin/$1 $2 $3 $4 $5

