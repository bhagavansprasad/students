struct student
{
	char name[50];
	int id;
	int grade;
}s1;
struct  employe
{
char name[50];
int id;
float salary;
char address[50];
}e1;

#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{
	int fd,val,fd1;
	char buff[10];
	char buffr[4],buffer[1000];
	int head=1,header=2;
	fd=open("s3.txt",O_RDWR);
	val=read(fd,buff,4);
	printf("value ==%d\n",val);
	printf("%s\n",buff);

	if(buff[0]=='2')
	{
		while(1)
		{
			val=read(fd,&s1,sizeof(s1));
			//write(fd,&s1,val);

			printf("%s\n%d\n%d\n",s1.name,s1.id,s1.grade); 
			if(val<sizeof(s1))
			{
				exit(0);

			}
		}
	}

	else
	
	{
	fd1=open("s.txt",O_RDWR);

	val=read(fd1,buffr,4);

	printf("%d",val);
	{

	if(buffr[0]=='2')

	{
		while(1)
		{
			val=read(fd1,&e1,sizeof(e1));
			printf("%s\t%d\t%f\t%s\t\n",e1.name,e1.id,e1.salary,e1.address); 
			if(val<sizeof(e1))
			{
				exit(0);

			}
		}
	}
	}
}

}

