#!/bin/bash

if [[test1 > ../bin/zeroes.exe == cat test_ans]]
then
    exit 1;
else
    exit 0;
fi