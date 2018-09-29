#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "structure.h"

int main()
{
	int rfd = 1,r = 1, i = 0;
	record1 s1[3];

	rfd = open("student.db", O_RDONLY, 0777);

	if(rfd < 0)
	{
		printf("open rfd and errno = %d   %d\n",rfd,errno);
		perror("open failed because ");
	}

	printf("open is successful \n");

	while(i<3)
	{
		r = read(rfd,&s1[i],sizeof(record1));

		if( r < 0)
		{
			printf("read retval and errno = %d   %d\n",r,errno);
			perror("reading is failed because ");
		}

		printf("%d st student details ----->",i);
		printf("NAME  = %s\n",s1[i].name);
		printf("AGE   = %d\n",s1[i].age);
		printf("CLASS = %d\n",s1[i].class);
		i++;
	}
	close(rfd);
}
