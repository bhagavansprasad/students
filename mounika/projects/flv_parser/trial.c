#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
/*struct student
{
short int roll_num;
char name[10];
}s1,s2;*/

struct student s1;
struct student s2;
main()
{
	int ld,fd1,fd2,rval,wval;
	char buff[100];
	fd1=open("c.txt",O_APPEND|O_RDWR|O_CREAT,0644);
	printf("fd1  :%d\n",fd1);
	wval=write(fd1,"1 Arjun\0 ",sizeof(struct student));
	printf("wval  :%d\t",wval);




	wval=write(fd1,"2 Bhanu\0",sizeof(struct student));
	printf("wval  :%d\t",wval);


	ld=lseek(fd1,0,SEEK_SET);

	printf("ld :%d\n",ld);
	rval=read(fd1,&s1,wval);


//	printf("buff :%s\n",buff);
	rval=read(fd1,&s2,wval);
	
	fd2=open("a.txt",O_APPEND|O_RDWR|O_CREAT,0644);
	write(fd2,&s1,sizeof(struct student));
	write(fd2,&s2,sizeof(struct student));


}
