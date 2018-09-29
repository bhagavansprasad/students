#include"stdio.h"
#define MSGSIZE 16
main()
{

	char *msg1="hello prasad 1";
	char *msg2="hello prasad 2";
	char *msg3="hello prasad 3";
	char inbuf[MSGSIZE];
	int p[2],j;
	//printf("p[0]=%d p[1]=%d\n",p[0],p[1]);
	printf("p[0]=%d p[1]=%d p[2]=%d p[3]=%d p[4]=%d\n",p[0],p[1],p[2],p[3],p[4]);
	pipe(p);
	printf("p[0]=%d p[1]=%d p[2]=%d p[3]=%d p[4]=%d\n",p[0],p[1],p[2],p[3],p[4]);
	write(p[1],msg1,MSGSIZE);
	write(p[1],msg2,MSGSIZE);
	write(p[1],msg3,MSGSIZE);

	for(j=0;j<3;j++)
	{

		read(p[0],inbuf,10);
		printf("%s\n",inbuf);

	}

	exit(0);

}
