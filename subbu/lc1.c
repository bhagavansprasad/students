#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>



int getwc(char *ptr);
int getlc(char *ptr);

main()
{
	int len=10,fd,a=0,b=0,s=0;
	char buff[415];
	int ret;
	fd=open("lc.txt",O_RDONLY);
	while(1)
	{
		ret=read(fd,buff,len);
		s=s+ret;
		buff[ret]='\0';
		printf("%s",buff);

		a+=getwc(buff);
			b+=getlc(buff);

		if(ret<len)
		  break;
	}
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",s);


}

	int getwc(char *ptr)
	{
		int i;
		int wc=0;
		for(i=1;ptr[i]!='\0';i++)
		{
			if((ptr[i]==' '||ptr[i]=='\n'))
			{
			if(ptr[i+1]!=' ')
			  wc=wc++;
			  }
		}
		return(wc);
	
	}
		int getlc(char *ptr)
	{
		int i;
		int wc=0;
		for(i=0;ptr[i]!='\0';i++)
		{
			if(ptr[i]=='\n')
			wc=wc++;
		}
		return(wc);
	}


