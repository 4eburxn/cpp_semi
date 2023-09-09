#!/bin/bash

g++ -Og -Wall -Wextra -pedantic -Ilib -o p $1 && ./p && rm p

