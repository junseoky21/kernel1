# kernel1

Kernel Module Practice

1. Configuration
It's important to switch to the kernel module that you're using.
To configure this, make changes to the Makefile
2. Running
To run,
sudo dmesg -C
make clean
make
sudo insmod main.ko
sudo rmmod main.ko
dmesg
