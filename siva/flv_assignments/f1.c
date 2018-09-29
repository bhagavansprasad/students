struct student
{
	char name[50];
	int grade;
	int id;
}s;
struct  employe
{
char name[50];
int id;
float salary;
char address[50];
}e;
#include<stdio.h>
#include<string.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>

main()
{
	int fd,i,fd1;
//	int head=1;
	char buf[4]="1";
	char buff[4]="2";

	fd=creat("f.txt",O_RDWR);
	if(fd==-1)
	{
		perror("file is not created\n");
		exit(0);
	}
    printf("file1 is created\n");
	write(fd,buf,4);
	for(i=0;i<5;i++)
	{
		strcpy(s.name,"siva");
		s.grade=1;
		s.id=657;
	write(fd,&s,sizeof(s));
	}
	printf("\twrite the 2 nd structure content\n");
    write(fd,buff,4);
	for(i=0;i<5;i++)
	{
	strcpy(e.name,"vamsi");
	e.id=657;
	e.salary=18000;
	strcpy(e.address,"MTM");
	write(fd,&e,sizeof(e));
	}
	close(fd);

}

