#include <stdio.h>
#define MSGSIZE 16
main()
{
	char *msg1="manohar";
	char inbuf[MSGSIZE];
	int p[2];
	pipe(p);
	write(p[1],msg1,MSGSIZE);
	read(p[0],inbuf,MSGSIZE);
	printf("%s\n",inbuf);
	exit(0);
}
