#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "structure.h"

int noe = 0;
typedef struct db student ;

student sd[10],buff[10];
int add (char *ch, int rollno)
{

	int i;
	int fd1,fd2;
	int rretval, wretval;

	strcpy(sd[noe].name,ch);
	sd[noe].rollno=rollno;
	fd1=open("mounika.txt",O_WRONLY | O_CREAT,0644);

	wretval=write(fd1,&sd[noe],sizeof(sd));
	
	close(fd1);

	fd2=open("mounika.txt",O_RDONLY,0);
	rretval=read(fd2,&buff[noe],sizeof(sd));
	printf("%d %s\n ",buff[noe].rollno,buff[noe].name);
	noe++;
	return 0;
}
int main()
{
	int i;
	int rollno[]={1,2,3,4,5,6,7,8};

	char*s[10]={"arjun","bindu","chethan","devi","eswar","geetha","hari","maheshwar"};
//	for(i=0;i<8;i++)
//	{ 
		add(s[0],rollno[0]);
//	}
	return 0;
}


