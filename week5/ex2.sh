#!/bin/s

file=num.txt
lock=$file.lock

if [ ! -f $file ]
then
	echo 0 > $file
fi

echo -e "lockfile: $lock"

while  [ ! ln $file $lock ]
do
	ln $file $lock
	
done

number=$(tail -n 1 $file)
echo -e "$(($number+1))" >> $file
rm -f $lock
