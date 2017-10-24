#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd = 0, retval = 0, len = 500;
	char buff[1024];
	fd=open("gcd.c" , O_RDONLY, 0744);
	//printf("%d\n",fd);
	while(1)
	{
		retval = read(fd,buff,len);
		//printf("--> retval %d\n", retval);
		buff[retval] = '\0';
		printf("%s\n",buff);
		if(retval < len)
			break;
	}
}
