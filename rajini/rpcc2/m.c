#include "stdio.h"
#include "fcntl.h"
#include "defs.h"
#include "fop.h"
main()
{
	char buff[100] = { 0 };
	int rfd, wfd, read_retval, write_retval,lseek_retval;

    printf("-->%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	rfd = aopen("t.txt", O_RDONLY, 0);
	printf("in main rfd is : %d\n",rfd);

	wfd = aopen("d.txt", O_RDWR|O_CREAT, 0777);
	printf("in main wfd is : %d\n",wfd);

	read_retval = aread(rfd, buff, MAX);

	printf("----->in main After read_retval :%d\n", read_retval);
	
	buff[read_retval] = '\0';

	printf("----->in main After read_retval :%d\n", read_retval);
	printf("----->in main After read buff   :%s\n", buff);

	write_retval = awrite(wfd, buff, read_retval);
	printf("--->After write_retval :%d\n", write_retval);

	lseek_retval = alseek(rfd, -10l, 2);
	printf("-->%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("-->After lseek retval :%d\n", lseek_retval);

	read_retval = aread(rfd, buff, MAX);
	buff[read_retval] = '\0';

	printf("-->After read_retval :%d\n", read_retval);
	printf("-->After read buff   :%s\n", buff);

	write_retval = awrite(wfd, buff, read_retval);
	printf("--->After write_retval :%d\n", write_retval);

	aclose(rfd);
	aclose(wfd);
	printf("-->%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
}

