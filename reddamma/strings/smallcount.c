#include<stdio.h>
main()
{
	int t;
	char s1[100]="Aura Networks in BANGALORE";
	t=get_small_case_count(s1);
	printf("%d\n",t);
}
int get_small_case_count(char *str)
{
	int i,sm=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='a'&&str[i]<='z')
			sm++;
	}
	return sm;
}

