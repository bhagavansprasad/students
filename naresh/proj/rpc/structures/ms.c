#include "stdio.h"
#include "fop.h"
#include "stdlib.h"
#include "fcntl.h"
#include "string.h"
main()
{
	int fd,fd1,w,r,len = 10;
	char buff[20];
	//printf("-->%d. %s, %s\n",_LINE_,_FUNCTION_,_FILE_);

	fd = aopen("t.txt",O_RDONLY,0);

	//printf("-->%d. %s, %s\n",_LINE_,_FUNCTION_,_FILE_);
	printf("fd--->%d\n",fd);

	fd1 = aopen("n.txt",O_CREAT|O_RDWR,0777);
	printf("%d",fd1);
//	printf("-->%d. %s, %s\n",_LINE_,_FUNCTION_,_FILE_);

	r=aread(fd,buff,len);
	buff[r] = '\0';
	//printf("-->%d. %s, %s\n",_LINE_,_FUNCTION_,_FILE_);

	w=awrite(fd1,buff,r);
	//printf("-->%d. %s, %s\n",_LINE_,_FUNCTION_,_FILE_);
	
	alseek(fd,-10l,2);
	
	r = aread(fd,buff,len);
	buff[r] = '\0';
	printf("%s",buff);
	
	w=awrite(fd1,buff,r);
	//printf("-->%d. %s, %s\n",_LINE_,_FUNCTION_,_FILE_);
	
	aclose(fd);
	aclose(fd1);
}
