#include "stdio.h"
#include "fcntl.h"
#include <unistd.h>
#include "string.h"
#include "defs.h"

int ard; 	
int read_audio_tag(int fd)
{
	char buff[3];
	int   p;
	ard = 0; 	

	ard += read(fd, buff, 1);

	p = buff[0];
	adata.soundformat  = ((p >> 4) & 15);

	adata.soundrate  = ((p >> 2) & 3);

	adata.soundsize = ((p >> 1) & 1);

	adata.soundtype = (p & 1);

	if(adata.soundformat = 10)
	{
		ard += read(fd, buff, 1);
		adata.aacpackettype = buff[0];
	}

	if(tdata.filter == 1);

	else
		audiotagbody(fd);

	return ard;
}

int audiotagbody(int fd)
{
	if(adata.soundformat == 10)
		aacaudiodata();

	else

		return 0;
}	

int aacaudiodata(int fd)
{
	if(adata.aacpackettype == 0);

	else if(adata.aacpackettype == 1);

	return 0;
}
