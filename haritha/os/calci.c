#include<stdio.h>
#include "string.h"
//#include <stdlib.h>
//#include <math.h>
int  main()
{
	int pid=0;
	int p1[2];
	int p2[2];

	pipe(p1);
	pipe(p2);

	pid = fork();
	if(pid == 0)
		child(p1[1],p2[0]);
	else
		parent(p2[1],p1[0]);
}


int child(int wfd, int rfd)
{
	char creq[100]= "add 100 200";
	
	char creply[100];

	int retval = 0;

	retval = write(wfd, creq, strlen(creq));
	printf("-->C. write retval :%d\n", retval);

	sleep(2);

	retval = read(rfd, creply ,100);
//	if(retval<0)
//	{

//		perror("error -- ");
//	}
	printf("-->C. read retval :%d\n", retval);
	printf("-->C. answer--> %s\n",creply );
}

int  parent(int wfd, int rfd)
{
	int sum=0, first = 0, second = 0;
	char sreq[100];
	
	char sreply[100];

	char cmd[10];
	int retval = 0;
	
	sleep(2);
	retval = read(rfd, sreq, 100);
	printf("-->S. read retval :%d\n", retval);
	sreq[retval] = '\0';

	printf("-->S. client's request :%s\n", sreq);
	sscanf(sreq, "%s %d %d", cmd, &first, &second);
	printf("-->S. cmd   :%s\n", cmd);
	printf("-->S. first :%d\n", first);
	printf("-->S. second:%d\n", second);

	sum = first + second;
	printf("-->S. sum :%d\n", sum);

	sprintf(sreply,"%d",sum);
	
	retval = write(wfd, sreply, strlen(sreply));
	printf("-->S.write retval :%d\n",retval);
	printf("-->S.write retval :%s\n",sreply);
}


