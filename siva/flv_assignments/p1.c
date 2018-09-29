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
	int fd,i,fd1,ret;
//	int head=1;
	char buf[4]="1234";
	char buff[4]="2";

	fd=open("s3.txt",O_RDWR|O_CREAT,0644);
	if(fd==-1)
	{
		perror("file is not created\n");
		exit(0);
	}
    printf("file1 is created\n");
	ret = write(fd,buf,4);
	printf("%s\n",buf);
	printf("ret : %d\n",ret);
	for(i=0;i<5;i++)
	{
		strcpy(s.name,"siva");
		s.grade=1;
		s.id=657;
	write(fd,&s,sizeof(s));
	}
	close(fd);
	printf("\tREAD THE SECOND FILE\n");
	/* file 2 is created*/
	fd1=open("s.txt",O_RDWR|O_CREAT,0644);
	if(fd1==-1)
	{
	perror("file2 is not created\n");
	exit(0);
	}
	printf("file 2 is created\n");
    write(fd1,buff,4);
	for(i=0;i<5;i++)
	{
	strcpy(e.name,"vamsi");
	e.id=657;
	e.salary=18000;
	strcpy(e.address,"MTM");
	write(fd1,&e,sizeof(e));
	}
	close(fd1);

}

