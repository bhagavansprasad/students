#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include "structure.h"

int main()
{
	int fd = 0, w = 0, i = 0;
	record1 s1[3] = {
		{"KIRAN", 20, 03},
		{"PRADEEP", 20, 03},
		{"PAVAN", 25, 03}
	};


	fd = open("student.db", O_CREAT|O_WRONLY, 0777);

	if(fd < 0)
	{
		printf("open fd and errno  = %d  , %d \n",fd,errno);
		perror("open failed because ");
	}
	printf("creating file is successful\n");

	while(i < 3)
	{
<<<<<<< building.c
		w = write(fd,&s1[i],sizeof(record1));

		if(w < 0)
		{
			printf("write retval and errno = %d   %d\n",w,errno);
			perror("write is failed because \n");
		}
		i++;
=======
		printf("write retval and errno = %d   %d\n",w,errno);
		perror("open failed because \n");
>>>>>>> 1.3
	}
<<<<<<< building.c
	printf("writing in the file is successful\n");
	printf("total write size = %d bytes \n",w);

=======
	printf("creating file is successful\n");
	printf("total byte size = %d\n",w);
>>>>>>> 1.3
	close(fd);
	return 0;
}
