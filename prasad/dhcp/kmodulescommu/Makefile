obj-m += pseudo.o pseudo.h
obj-m += kmodule1.o
obj-m += kmodule2.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf *.ko
	rm -rf *.o
	rm -rf Module.symvers
