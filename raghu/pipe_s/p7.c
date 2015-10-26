#include <stdio.h>
#define SIZE 200

main()
{
	int p[2];
	int pid,fd,c=0;
	char *msg = "hi this is raghu";
	pipe(p);
	while(1)
	{
		fd = write(p[1],msg,SIZE);
		
			printf("fd----->%d",fd);
		if(fd < 0)
			break;
		else
		{
			c++;
			printf("   %d",c);
		}
	}
	printf("%d\n",c);
}
