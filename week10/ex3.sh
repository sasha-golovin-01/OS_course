#!/bin/bash
touch _ex3.txt
echo "Sasha is monster!" >> _ex3.txt
chmod a-x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod uo+rwx  _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "Permission trials: " >> ex3.txt
chmod 660 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 775 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 777 _ex3.txt 
ls -l _ex3.txt >> ex3.txt
