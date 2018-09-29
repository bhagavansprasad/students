#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd=-1,fd1=-1, read_retval = 0,write_retval,pos,s,t;
	char buf[1000], buf1[1000];

	fd=aopen("a.txt",O_RDONLY);
	if(fd==-1)
	{
		perror("file can not opened\n");
		return 0;
	}
	fd1=aopen("b.txt",O_WRONLY);
	if(fd1==-1)
	{
		perror("file can not opened\n");
		return 0;
	}
	read_retval = aread(fd, buf, 10);
	if(read_retval < 0)
	{
		perror("---> read failed\n");
		return 0;
	}
	buf[read_retval]='\0';
	printf("---->read buff len :%d data:%s\n", read_retval, buf);
	
	write_retval=awrite(fd1, buf, read_retval);
	if(write_retval==-1)
	{
		perror("----> write failed\n");
		return 0;
	}
	printf("---->write retval :%d \n", write_retval);
	
	pos = alseek(fd, -20, SEEK_END);
	if(pos==-1)
	{
		perror("---> lseek failed\n");
		return 0;
	}

	printf("-->lseek :%d\n", pos);

	pos = alseek(fd, pos, SEEK_SET);
	read_retval = read(fd, buf, 20);
	if(read_retval == -1)
	{
		perror("--->read failed\n");
		return 0;
	}
	buf[read_retval] = '\0';
	printf("-->read buf :%d, data :%s \n", read_retval, buf);

	write_retval = awrite(fd1, buf, read_retval);
	if(t==-1)
	{
		perror("----> write failed\n");
		return 0;
	}

	printf("-->write len :%d\n", write_retval);
	printf("copy done\n");
}

