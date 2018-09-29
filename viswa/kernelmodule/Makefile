obj-m+= k2k1.o

all:
	make -C /lib/modules1/$(shell uname -r)/build M=$(PWD) modules1

clean :
	make -C /lib/modules1/$(shell uname -r)/build M=$(PWD) clean
