#include <stdio.h>
#include <fcntl.h>
#include "fop.h"
main()
{
	int fop=0,fop1=0,rret=0,len=10;
	char buff[100];
	fop  = aopen("t1.txt",O_RDONLY,0);
	printf("%d",fop);
	fop1 = aopen("t2.txt",O_CREAT|O_WRONLY,0777);
	printf("%d",fop1);
	while(1)
	{
		rret = aread(fop,buff,len);
		buff[rret] = '\0';
		awrite(fop1,buff,rret);
		if(rret<len)
			break;
	}
	aclose(fop);
	aclose(fop1);
}
