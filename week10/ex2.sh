#!/bin/bash
mkdir week01
cd week01
touch file.txt
echo "Sasha is monster" >> file.txt
cd ..
mkdir week10
cd week10
link ../week01/file.txt _ex2.txt
num = ${"$(ls -i ../week01/file.txt)"%% *}
cd ..
echo "all links to the file.txt: " >> ex2.txt
find ../ -inum $num >> ex2.txt
echo "removement..." >> ex2.txt
find ../ -inum $num -exec rm {} \;

