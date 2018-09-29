#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include"struct.h"
main()
{
	student s[4];
	int fd,w,i;
	strcpy(s[0].name,"prasad");
	s[0].age= 15;
	s[0].class = 10;
//	printf("sname=%s\n",s[1].name);
	strcpy(s[1].name,"krishna");
	s[1].age= 14;
	s[1].class = 10;
	strcpy(s[2].name,"noor");
	s[2].age= 16;
	s[2].class = 10;
	strcpy(s[3].name,"noor1");
	s[3].age= 16;
	s[3].class = 10;

	creat("student.db", S_IRWXU | S_IRWXG);
	fd=open("student.db", O_CREAT | O_RDWR);
	if(fd<0) perror("file cannot be opened");
	//fd=open("student.db",O_WRONLY);
	printf("fd=%d\n",fd);
for(i=0;i<4;i++)
{
	w=write(fd,&s[i],sizeof(student));
}
	printf("write=%d\n",w);
	printf("address=%u\n",&s[0]);

	/*printf("name=%s\n",s.name);
	printf("age=%d\n",stu.age);
	printf("class=%d\n",stu.class);*/
	close(fd);
}
