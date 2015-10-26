#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	char buff[200];
	int i,n=10,fd,retval,j,word=0;
	fd=open("a.txt",O_RDONLY);
	for(i=1;i<=n;i++)
	{
		retval=read(fd,buff,20);
		printf("%d\n",retval);
		buff[retval]='\0';
		printf("%s\n",buff);
		if(buff[0]>=65 && buff[j]<=122)
		{
			word++;
		}
		for(i=1;buff[j]!='\0';j++)
		{
			if(buff[j]==' ')
			{
				continue;
			}
			else
				if((buff[j-1]>=65 && buff[j-1]<=122)^(buff[j]>=65 && buff[j]<=122))
				{
					word++;
				}
			printf("%c",buff[j]);
		}
		printf("%d",word);
		if(retval==0)
		{
			break;
		}
	}
	close(fd);
}


