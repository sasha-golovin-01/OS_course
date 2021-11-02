dd if=/dev/zero of=lofs.img bs=1M count=50
sudo losetup -fP lofs.iiimg
sudo losetup -a
sudo mkfs.ext4 ./lofsi.img
mkdir lofsdisk
sudo mount -o loop /dev/loop5 ./lofsdisk/
df -hP lofsdisk
