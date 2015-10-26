#include<stdio.h>
#include <fcntl.h>
#include <errno.h>
main()
{
	int fd, fd1, r, w, c, ln=10;
	char buf[100];
	fd = open("a.txt", O_RDWR);
	fd1 = open("b.txt", O_CREAT|O_RDWR, 0777);
	printf("%d\n",fd);
	printf("%d\n",fd1);

	while(1)
	{
		r = read(fd, buf, ln);
		buf[r] = '\0';
		c = aconvt( buf );
		printf("%s\n",buf);
		w = write(fd1,buf,r);
		printf("%s\n",buf);

		if(w<0)
		{
			perror("not writing due to:");
			printf("%d",errno);
		}
		if(r<ln)
			break;

	}

	close(fd);
	close(fd1);
	printf("%d\n%d", fd, fd1);
}

/*function to convert upper case */

int aconvt( char *buf)
{
	int i;
	for(i = 0; buf[i] != '\0'; i++)
	{
		if(buf[i] >= 65&&buf[i] <= 90)
		{
			buf[i] = buf[i]+32;
		}
	else if( buf[i] >= 97&&buf[i]<=123)
		{
		 buf[i] = buf[i]-32;
		 }
		 else
      		 buf[i];
	}
	return(i);
}



