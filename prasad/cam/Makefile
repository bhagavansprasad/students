uvcvideo-objs  := uvc_driver.o uvc_queue.o uvc_v4l2.o uvc_video.o uvc_ctrl.o \
		  uvc_status.o uvc_isight.o 
obj-m += uvcvideo.o
all:
	make -C /lib/modules/2.6.35-28-server/build M=$(PWD) modules
clean:
	make -C /lib/modules/2.6.35-28-server/build M=$(PWD) clean
