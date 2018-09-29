#include<stdio.h>
#include<fcntl.h>
int main()
{
	char buff[100];
	int fd=0,ret,s,t,len=10;
	fd=open("t.txt",O_RDONLY);
	while(1)
	{
		ret=read(fd,buff,len);
		buff[ret]='\0';
		printf("%s",buff);
		s=get_word_count(buff);
		t=get_line_count(buff);
		if(ret<len)
		{
			break;
		}
	}
	printf("\n");
	printf("%d\n",s);
	printf("%d\n",t);
	close(fd);
}
int get_word_count(char *str)
{
	int i,w=0;
	for(i=0;str[i]!='\0';i++)
	{
		while(str[i]==' ')
			i++;
		if(str[i]!=' ' &&str[i]!='\0')
			w++;
		while(str[i]!=' '&&str[i]!='\0')
			i++;

	}
	return w;
}
int get_line_count(char *s)
{
	int i;
	static int lc=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='\n')
			lc++;
	}
	return lc;
}

