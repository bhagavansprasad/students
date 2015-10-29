#include<stdio.h>
main()
{
	char str[]="  h     e      l     l     o  " ;
	int c=0;
	c=word_count(str);
	printf("no of words in string :%d \n",c);
}
int word_count(char *str)
{
	int i=0, w=0;
	for(i=0; str[i] != '\0';i++)
	{
		while(str[i]==' ')
			i++;
		if(str[i]!=' ' && str[i]!='\0')
					w++;
		while(str[i]!=' ' && str[i]!='\0')
			i++;
	}
	return w;
}

