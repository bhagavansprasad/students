#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
main()
{
	char buff[100];
	int fd=0,ret, t;
	fd=open("t.txt",O_RDONLY);
	ret=read(fd,buff,100);
	buff[100]='\0';
	printf("%s",buff);
	t=get_word_count(buff);
	printf("%d", t);

}
int get_word_count(char *s)
{
	int w=0,i;
	for(i=0;s[i]!='\0';i++)
	{
		while(s[i]==' ')
		{
			i++;
		}
		if(s[i]=='\n')
		{
		continue;
		}

		if(s[i]!=' '&&s[i]!='\0')
		{
			w++;
		}
	
		
		while(s[i]!=' '&&s[i]!='\0')
		{
			i++;
		}
	}
	return w;
}
