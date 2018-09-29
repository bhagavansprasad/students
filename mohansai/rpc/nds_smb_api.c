#include "stdio.h"
#include "string.h"
#include "file_db.h"

int nds_smb_open(char *filename, int mode)
{
	int fd;
	int retval;
	file_info fdata;

	fd = sys_open(filename, mode);

	strcpy(fdata.name, filename);
	fdata.mode = mode;
	fdata.descriptor = fd;
	fdata.offset = 0;

	retval = add_fcb_to_list(&fdata);

	if (retval < 0 )
		return -1;

	return fd;
}

int nds_smb_read(int fd ,char *pbuff, int rlen)
{
	int retval;
	file_info *fcb = fd_check(fd);

	if (fcb == NULL)
		return -1;

	retval = sys_read(pbuff,  rlen ,fcb);
	//printf("retval %d\n\r",retval);
	return retval;
}

int nds_smb_write(int fd, char *pbuff, int rlen)
{
	int retval;
	
	file_info *fcb = fd_check(fd);
	if (fcb == NULL)
		return -1;

	retval = sys_write(pbuff,  rlen ,fcb);
	//printf("retval %d\n\r",retval);
	return retval;
}


int nds_smb_close(int fd)
{
	int retval;

	retval = sys_close(fd);	
	return retval;
}


