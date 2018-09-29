#include <stdio.h>
char* astrchr(const char* p , const char ch);
main()
{
	const char s1[] = "aura net net name";
	const char ch = 'n';
	char *b;
	b=astrchr(s1,ch);
	printf("ch %c is find out at %s\n",ch,b);
}
char* astrchr(const char* p,const char ch)
{
	int j,i;
	static char p1[20];
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]==ch)
		{
			for(j=0;p[i]!='\0';j++)
			{
				p1[j]=p[i];
				i++;
			}
			p1[j]='\0';
			break;
		}
	}
	return(p1);
}
