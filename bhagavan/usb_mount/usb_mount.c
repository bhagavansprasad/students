main()
{
	mountUSB();
}

int mountUSB()
{
    int mountAttempts;
    int status; 
 
    mountAttempts = 0;
    status = 0;
     
    do
    {   
		//status = mount("/dev/sda1", "/media/usb0", "vfat", MS_MGC_VAL | MS_RDONLY | MS_NOSUID, "");
        status = mount("/dev/sda1", "/media/usb0", "vfat", MS_MGC_VAL | MS_NOSUID, "");
        if(status != SUCCESS)
            sleep(1);
        mountAttempts++;
    }while(status != SUCCESS && mountAttempts < 3);
     
    printf("USB mount - status = %s\n", strerror(errno));
}

void umountUSB()
{
    int status;
    status = umount("/media/usb0");
     
    printf("USB unmount - status = %s\n", strerror(errno)); 
}
