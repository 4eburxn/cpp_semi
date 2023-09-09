#!/bin/bash

g++ -Og -Wall -Wextra -pedantic -Ilib -o bin/$1 $1 && bin/$1

