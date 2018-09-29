#include <stdio.h>
#include <fcntl.h>
main()
{
	int t,t1,rval=0,l=10;
	char buff[100];

	t = aopen("file.c", O_RDONLY, 0);

	while(1)
	{
		rval=aread(t,buff,l);
		buff[rval]='\0';
		if(l>rval)
			break;
		printf("%d\n",rval);
		printf("%s\n",buff);


	}
	t1=aclose(t);
	close(t1);
}		

