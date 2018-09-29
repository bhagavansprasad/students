#include<stdio.h>
#include<string.h>
main()
{
	int t;
	char s1[200]="Aura Networks In Bangalore";
	t=get_capital_count(s1);
	printf("%d\n",t);
}
int get_capital_count(char *str)
{
	int i,cp=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
			cp++;
	}
	return cp;
}

