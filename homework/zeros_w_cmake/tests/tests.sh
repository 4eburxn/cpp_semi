#!/bin/bash

if [[ $(cat ../tests/test1 | ../bin/zeroes.exe) = $(cat ../tests/test1_ans) ]]
then
    exit 0;
else
    exit 1;
fi