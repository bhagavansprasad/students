#include<stdio.h>
#include<string.h>

void main()
{
	char s[100]=" aura \n networks \n";

	int lc= get_line_count(s);

	printf("lc : is %d, for string %s\n",lc,s);
}

int get_line_count(char *p)
{

	int i,lc=0;

	for(i=0;p[i]!=0;i++)
	{
		if(p[i]=='\n')
			lc++;
	}

	return lc;
}
