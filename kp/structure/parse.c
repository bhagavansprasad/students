#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "struct.h"
main()
{
	int fd,r,i;
	student s[4];
	fd=open("student.db",O_RDONLY);
	for(i=0;i<4;i++)
	{	
		r=read(fd,&s[i].record,4);
		r=read(fd,&s[i].name,s[i].record-8);
		r=read(fd,&s[i].age,4);
		r=read(fd,&s[i].class,4);
	}
	printf("record=%d\n",s[0].record);
	printf("name=%s\n",s[0].name);
	printf("age=%d\n",s[0].age);
	printf("class=%d\n",s[0].class);
}

