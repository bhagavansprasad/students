#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd1,fd2,len=10,r,w,c;
	char buff[100],con[100];
	fd1=open("togg1.txt",O_RDONLY,0);
	fd2=open("togg2.txt",O_CREAT|O_RDWR,0);
	while(1)
	{
		r=read(fd1,buff,len);
		buff[r]='\0';
		c=aconvert(con,buff);
		w=write(fd2,con,r);
		printf("%s\n",con);
		if(r<len)
			break;
	}
	printf("%d",c);
}
int aconvert(char *d,char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>=65&&s[i]<=91)
			d[i]=s[i]+32;
		if(s[i]>=97&&s[i]<=122)
			d[i]=s[i]-32;
	}
	return(i);
}

