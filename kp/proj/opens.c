#include<stdio.h>
#include<fcntl.h>
auraopens(&struct)
{

	switch(sd.cmd) 
	{
case :1
	  aopen(sd.fname,sd.mode);
	  break;
case :2
	  aread(sd.fd,sd.buf,sd.count);
	  break;
case :3
	  awrite(sd.fd,sd.buf,sd.count);
	  break;
case :4
	  alseek(sd.fd,sd.offset,sd.whence);
	  break;
case :5
	  aclose(sd.fd);
	  break;
	}
}
