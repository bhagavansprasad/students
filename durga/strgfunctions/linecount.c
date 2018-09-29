#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd, r, ln=10,s=0;
	char buf[100];

	fd = open("a.txt",O_RDWR);
	printf("%d\n",fd);

	while(1)
	{
    
     r = read( fd, buf,ln);

	 buf[r]='\0';
	 s += linecunt(buf);
	 if(r<ln)
	 break;
	 }
	 printf("%d\n",s);
}

/*function to get the numer of lines in a file*/

int linecunt( char *pbuf)
{
	int i,c=0;
	for(i=0;pbuf[i]!='\0';i++)
	{
		if( pbuf[i]=='\n')
			c++;
	}
	return(c);
}

