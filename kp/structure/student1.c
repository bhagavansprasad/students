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
	s[0].record= sizeof(s[0].age)+ strlen(s[0].name)+1+sizeof(s[0].class);

	strcpy(s[1].name,"krishna");
	s[1].age= 14;
	s[1].class = 10;
	s[1].record= sizeof(s[1].age)+ strlen(s[1].name)+1+sizeof(s[1].class);
	strcpy(s[2].name,"noor");
	s[2].age= 16;
	s[2].class = 10;
	s[2].record= sizeof(s[2].age)+ strlen(s[2].name)+1+sizeof(s[2].class);
	strcpy(s[3].name,"noor1");
	s[3].age= 16;
	s[3].class = 10;
	s[3].record= sizeof(s[3].age)+ strlen(s[3].name)+1+sizeof(s[3].class);

	creat("student.db", S_IRWXU | S_IRWXG);
	fd=open("student.db", O_CREAT | O_RDWR);
	if(fd<0) perror("file cannot be opened");

	printf("fd=%d\n",fd);
for(i=0;i<4;i++)
{
	w=write(fd,&s[i].record,sizeof(s[i].record)+strlen(s[i].name)+1);

	w=write(fd,&s[i].age,sizeof (s[i].age)+sizeof(s[i].class));
}
	printf("record=%d\n",s[0].record);
//	printf("address=%u\n",&s[0]);


printf("name=%s\n",s[0].name);
/*	printf("age=%d\n",stu.age);
	printf("class=%d\n",stu.class);*/
	close(fd);
}
