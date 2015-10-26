obj-m += kernelmodule1.o
obj-m += kernelmodule2.o
obj-m += kernelmodule3.o
obj-m += licence.o
obj-m += command_line_argu.o
obj-m += startstop.o
startstop-objs := start.o stop.o
obj-m += keyboards_leds.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf *.ko
	rm -rf *.o
	rm -rf Module.symvers
