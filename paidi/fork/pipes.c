#include <stdio.h>
 #define MSGSIZE 5
main()
{
	char * s1 = "hello,world1";
	char * s2 = "hello,world2";
	char * s3 = "hello,world3";
	char buf[MSGSIZE];
	int p[2],j;
	pipe(p);
	write(p[1],s1,MSGSIZE);
	write(p[1],s2,MSGSIZE);
	write(p[1],s3,MSGSIZE);
	for(j = 0;j < 3;j++)
	{
		read(p[0],buf,MSGSIZE);
		printf("%s\n",buf);
		printf("p[0]is-->%d p[1]is-->%d \n",p[0],p[1]);
	}
}
