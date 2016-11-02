#include <stdio.h>
#define MSGSIZE 16
main()
{
	char *m1="hello,world";
	char *m2="hai";
	char *m3="hw r u";
	char inbuf[MSGSIZE];
	int p[2],j;

	pipe(p);
	write(p[1],m1,MSGSIZE);
	write(p[1],m2,MSGSIZE);
	write(p[1],m3,MSGSIZE);

	for(j = 0; j < 3; j++)
	{
		read(p[0], inbuf, MSGSIZE);
		printf("%s\n",inbuf);
	}

}
