#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd,r,s=0,ln=10;
	char buf[100];
	fd = open("a.txt",O_RDWR);
	printf("%d\n",fd);
	while(1)
	{
		r = read(fd, buf,ln);
		buf[r]='\0';
		s += wordcount(buf);
		if( r < ln)
			break;
	}
	printf("%d\t",s);

}

/*function to count the number of wrodes in a file*/

int wordcount(char *pbuf)
{
	int i=0,c=0;
	for(i=0;pbuf[i]!='\0';i++)
	{
		if( (pbuf[i]!=' ' && pbuf[i-1]==' ' )&& pbuf[i-1]!='\0')
			c++;
	}
	return(c);
}

