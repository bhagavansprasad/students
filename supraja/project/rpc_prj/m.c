#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "fop.h"
#include "struct_replay.h"
main()
{
	int fd1,fd2,rval,len = 10,wval,lval;
	char buff[50];
	fd1 = aopen ("t.txt",O_RDONLY,0);
	if(fd1 == -1)
	{
		printf("fd1 open unsuccessfull\n");
		printf("error no : %d\n",errno);
		perror("error is: ");
	}
	fd2 = aopen ("r.txt",O_CREAT|O_RDWR,0777);
	if(fd2 == -1)
	{
		printf("fd2 open unsuccessfull\n");
		printf("error no : %d\n",errno);
		perror("error is: \n");
	}
	//while(1)
	//{
		rval = aread(fd1,buff,len);
		buff[rval]='\0';
		printf("%s\n",buff);
		wval = awrite(fd2,buff,rval);
		lval = alseek(fd1,-10l,3);
		rval = aread(fd1,buff,len);
		buff[rval]='\0';
		printf("%s\n",buff);
		wval = awrite(fd2,buff,rval);
	//	if(rval < len)
	//		break;

	//}
	aclose(fd1);
	aclose(fd2);
}
