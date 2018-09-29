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
	st student;
	st1 student1;
	int fd2=-1,fd4=-1,i=0;
	char buff[4]="v-2 ";
	char buff1[4]="";
	char buff2[4]="";
	fd2=open("student.db",O_RDONLY);
	if(fd2 == -1)
	{
		perror("file read failed\n");
		return 0;
	}

	fd4=open("student1.db",O_RDONLY);
	if(fd4 == -1)
	{
		perror("file read failed\n");
		return 0;
	}
	int ret2=read(fd4,buff2,4);
	buff2[ret2]='\0';
	if(!strcmp(buff1,buff))
	{	

		printf("NAME   	 |AGE  |CLASS  |\n");
		printf("--------------------------------------\n");
		for(i=0;i<=4;i++)
		{
		read(fd2, &student, sizeof(student));
		printf("%-8.7s %-5.2d %-5.2d\n",student.name,student.age,student.class);
		}
	}
	if(1)
	{
		printf("NAME   	 |AGE  |CLASS  |MARKS |GRADE  \n");
		printf("--------------------------------------\n");
		for(i=0;i<=4;i++)
		{
		read(fd4, &student1, sizeof(student1));
		printf("%-8.7s |%-5.2d| %-5.2d |%-5.2d |%-5.2c\n",student1.name,student1.age,student1.class,student1.marks,student1.grade);
		}

	}
	return 0;
	close(fd2);
	close(fd4);
}


















