#include<stdio.h>
main()
{

	//char str[100]={'H','e','m','A','L','a','T','H','a'};
	char str[100]="HemALaTHa";
	get_lower_count(str);
}

int get_lower_count(char *p)
{
	int i;

	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]>=97 && p[i]<=123)
		{
			printf("lower count:%c\n", p[i]);
		}
	}
	return 0;
}

