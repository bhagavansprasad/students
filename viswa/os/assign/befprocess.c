// open before fork();

#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd ,len = 10 , pid ,ret= 0, retw = 0 ;
	char buff[21];
	fd = open ("t.txt", O_RDWR,0777);
	pid = fork();

	if( pid == 0)
	{
		ret = read(fd ,buff ,len);
		printf("child read ret %d\n",ret);
		printf("child buff read %s\n",buff);
		retw = write(fd , buff , len);
		printf("child write ret %d \n", retw);
		printf("child buff write %s\n",buff);

		printf("child close return value %d",close(fd));
	}
	else
	{
		ret = read(fd ,buff ,len);
		printf("parent read ret %d\n",ret);
		printf("parent  buff read %s\n",buff);

		retw = write(fd , buff , len);
		printf("parent write ret %d \n", retw);
		printf("parent  buff write %s\n",buff);

		printf("parent close return value %d",close(fd));

	}
}
