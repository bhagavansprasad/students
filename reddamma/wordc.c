#include<stdio.h>
#include<string.h>
main()
{
	int t;
	char s1[100]="     aura net    ";
	t=get_word_count(s1);
	printf("%d\n",t);
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



