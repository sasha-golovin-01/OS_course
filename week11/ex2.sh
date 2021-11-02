sudo chmod 777 lofsdisk
sudo touch lofsdisk/file1
sudo chmod 777 lofsdisk/file1
echo "Sasha" >> lofsdisk/file1
sudo touch lofsdisk/file2
sudo chmod 777 lofsdisk/file2
echo "Monster" >> lofsdisk/file2
gcc -o ex2.out ex2.c
sudo mkdir lofsdisk/bin
sudo cp -r /bin/bash lofsdisk/bin
sudo cp -r /bin/cat lofsdisk/bin
sudo cp -r /bin/echo lofsdisk/bin
sudo cp -r /bin/ls lofsdisk/bin
sudo mkdir lofsdisk/lib
sudo mkdir lofsdisk/lib/x86_64-linux-gnu/
sudo mkdir lofsdisk/lib64
path='./lofsdisk'
list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp  -v "$i" "${path}${i}"; done
list="$(ldd /bin/ls | egrep -o '/lib64.*\.[0-9]')"
for i in $list; do sudo cp  -v "$i" "${path}${i}"; done
list="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp  -v "$i" "${path}${i}"; done
list="$(ldd /bin/bash | egrep -o '/lib64.*\.[0-9]')"
for i in $list; do sudo cp  -v "$i" "${path}${i}"; done
list="$(ldd /bin/echo | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp  -v "$i" "${path}${i}"; done
list="$(ldd /bin/echo | egrep -o '/lib64.*\.[0-9]')"
for i in $list; do sudo cp  -v "$i" "${path}${i}"; done
list="$(ldd /bin/cat | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp  -v "$i" "${path}${i}"; done
list="$(ldd /bin/cat | egrep -o '/lib64.*\.[0-9]')"
for i in $list; do sudo cp  -v "$i" "${path}${i}"; done
cd lofsdisk
gcc -o ex2.out ../ex2.c
sudo chroot . ./ex2.out >> ../ex2.txt
./ex2.out >> ../ex2.txt
