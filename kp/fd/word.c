#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
	int r,w,fd,l;
	int a=0,b=0,c=0;
	char buf[200];
	fd=open("tt.txt",O_RDONLY);
	while(1)
	{
		r=read(fd,buf,100);
		buf[r]='\0';
		if(r==0)
		{
			break;
		}
		w=getwordcount(buf);
		l=getlinecount(buf);
		printf("no of words is %d\n",w);
		printf("no of line is %d\n",l);
		a=a+w;
		b=b+l;
		c=c+r;
	}
	printf("total no of words=%d\n",a);
	printf("total no of lines=%d\n",b);
	printf("total no of character=%d\n",c);
	close(fd);
}
int getwordcount(char*p)
{
	int count=0,i;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]!=' '&&p[i+1]==' '||p[i]=='\n')
		{
			count++;
		}
		if(p[i]==' '&&p[i+1]=='\n')
		{
			count--;
		}
	}
	return count;
}
int getlinecount(char*p)
{
	int line=0,j;
	for(j=0;p[j]!='\0';j++)
	{
		if(p[j]=='\n')
		{
			line++;
		}
	}
	return line;
}

