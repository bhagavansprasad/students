#include "pseudo.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>		


main()
{
    int file_desc = open(DEVICE_FILE_NAME, 0);
    char *msg = "Message passed by ioctl to the kernel module\n";
    if (file_desc < 0)
    {
	printf("Can't open device file: %s\n", DEVICE_FILE_NAME);
	exit(-1);
    }

    ioctl(file_desc, FUN1, msg);
    ioctl(file_desc, FUN2, msg);
    close(file_desc);

}
