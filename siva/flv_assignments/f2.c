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
	int fd,val;
	char buff[4];
	char buffr[4];
	
	fd=open("f.txt",O_RDWR);
	val=read(fd,buff,4);
	printf("value ==%d\n",val);
	printf("%s\n",buff);

	if(buff[0]=='1')
	{
		while(1)
		{
			val=read(fd,&s1,sizeof(s1));
			//write(fd,&s1,val);

			printf("%s\n%d\n%d\n",s1.name,s1.id,s1.grade); 
			if(val==62)
			{
				exit(0);

			}
		}
	}

	else
	
	{
	lseek(fd,63,SEEK_END);

	if(buffr[0]=='2')

	{
		while(1)
		{
			val=read(fd,&e1,sizeof(e1));
			printf("%s\t%d\t%f\t%s\t\n",e1.name,e1.id,e1.salary,e1.address); 
			if(val<sizeof(e1))
			{
				exit(0);

			}
		}
	}
	}
}



