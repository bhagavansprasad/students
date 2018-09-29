#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>
#include <string.h>
#include <fcntl.h>
typedef struct 
{	
	char name[124];
	int age;
	int class;
}st;
typedef struct 
{
	char name[124];
	int age;
	int class;
	int marks;
	char grade;
}st1;
int main()
{
	st student[5];
	st1 student1[5];
	int i=0;
	int fd1=-1,fd2=-1,fd3=-1,fd4=-1;
	char buff1[4]="";
	char buff2[4]="";
	char version1[4]="v-1 ";
	char version2[4]="v-2 ";
	fd1=creat("student.db",O_CREAT|S_IRUSR|S_IWUSR);
	fd2=open("student.db",O_RDWR|O_APPEND);
	if(fd2==-1)
	{
		perror("student.db creation file opened failed\n");
		return 0;
	}
	fd3=creat("student1.db",O_CREAT|S_IRUSR|S_IWUSR);
	
	fd4=open("student1.db",O_RDWR|O_APPEND);
	if(fd4==-1)
	{
		perror("student1.db creation file opened failed\n");
		return 0;
	}
	if(1)
	{
	write(fd2,version1,4);
	write(fd4,version2,4);
	}
	int ret1=read(fd2,buff1,4);
	int ret2=read(fd4,buff2,4);
	if(1)
	{	
		st student[5]={
					{"madhur",23,10},
					{"prasad",24,12},
					{"siva",25,14},
					{"paidi",25,15},
					{"subbu",26,16}
				};
		for(i=0;i<=4;i++)
		write(fd2, &student[i], sizeof(student));
	}
	if(1)
	{
		st1 student1[5]={
					{"manohar",23,10,75,'A'},
					{"vijay",24,12,60,'B'},
					{"siva",25,14,50,'C'},
					{"paidi",25,15,45,'D'},
					{"sudha",26,16,85,'A'}
				};
		for(i=0;i<=4;i++)
		write(fd4, &student1[i], sizeof(student1));
	}
	return 0;
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}
