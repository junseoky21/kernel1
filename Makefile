obj-m += main.o

#KDIR = ~/kernel/linux-4.14.78
#KDIR = /usr/src/linux-headers-4.15.0-36-generic
KDIR = ~/kernel/linux-headers-4.15.0-36
all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order
