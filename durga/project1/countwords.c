#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd, c=0, r = 0, w = 0,ln = 5, i, flag=1;
	char pbuf[100];
	fd = open("prasad.txt", O_RDONLY,0);
	printf("%d\n",fd);

	while(1)
	{
		r = read(fd, pbuf, ln);
	//	printf("%d\n",r);
		pbuf[r]='\0';
		printf("%s\n",pbuf);
		for(i=1;pbuf[i]!='\0';i++)
		{
			if(pbuf[i]==' '||pbuf[i]=='\n'||pbuf[i]=='\t')
			{
				flag=1;
			//	printf("%d",c);			
			}
        else if(flag==1)
		{
		flag=0;
		c++;
		}
		}

		if(r<ln)

			break;
	}

	printf("words :%d\n",c);
}

