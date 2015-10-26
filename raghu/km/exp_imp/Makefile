obj-m += expimp.o
obj-m += imp.o

expimp-objs := 1km.o fact.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
