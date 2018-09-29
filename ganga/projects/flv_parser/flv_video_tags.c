#include "stdio.h"
#include "fcntl.h"
#include <unistd.h>
#include "string.h"
#include "defs.h"

int vrd;
char buff[10];
int read_video_tag(int fd)
{
	int i, retval = 0,wretval = 0, mask = 0xF;
	int p;
	char *cp;
	char buff1[1024] = " ";
	vrd  = 0;
	extern fd6, fd7;

	vrd += read(fd, buff, 1);

	p = buff[0];
	vdata.frame_type = ((p >> 4) & mask);

	vdata.codecID = (p & mask);

	if(vdata.codecID == 7)
	{
		vrd += read(fd, buff, 1);
		vdata.AVCpackettype = buff[0];
	}

	if(vdata.codecID == 7)
	{
		vrd += read(fd, buff, 3);

		cp = (char *)&vdata.compositiontime;
		for(i = 0; i <= 2; i++)
		{
			*cp = buff[i];
			cp++;
		}
	}

	if(tdata.filter == 1);

	else
		videotagbody(fd);

	return vrd;
}

int videotagbody(int fd)
{
	if(vdata.frame_type == 5)
		vrd += read(fd, buff, 1);
	else
	{
		if(vdata.codecID == 2);

		if(vdata.codecID == 3);

		if(vdata.codecID == 4);

		if(vdata.codecID == 5);

		if(vdata.codecID == 6);

		if(vdata.codecID == 7)
			AVCVIDEOPACKET(fd);
	}

	return vrd;
}

int AVCVIDEOPACKET(int fd)
{
	if(vdata.AVCpackettype == 0)

		if(vdata.AVCpackettype == 1)

			return 0;
}
