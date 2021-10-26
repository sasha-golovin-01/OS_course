#!/bin/bash
mkdir tmp
cd tmp
touch file1
touch file2
cd ..

link tmp/file1 tmp/link1

gcc ex4.c -o ex4
./ex4 > ex4.txt
