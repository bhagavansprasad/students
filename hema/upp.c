#include<stdio.h>
main()
{
            int i=0;
		char s[5]="f";
		is_upper(s);
		if(s[i]==1)
		{
			printf("string is upper " );

		}
		else 
		printf("string is lower");
}
int is_upper(char *ch)
{
	int i=0;
	if(ch[i]>=65&&ch[i]<=91)
	{ 
		return 1;
	}
return i;
}
