#include <stdio.h>
int a_strcasecmp(char *,char *);	
char upper_to_lower(char );
char lower_to_upper(char );
main()
{
	char str[10]="NAGESH";
	char ptr[10]="nagesh";
	a_strcasecmp(str,ptr);	
}
int a_strcasecmp(char *str,char *ptr)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(lower_to_upper(str[i]) != lower_to_upper(ptr[i]))
		{
			printf("both are not equal\n");
			break;
		}
	}
		printf("both are equal\n");
}
char upper_to_lower(char s)
{
	if(s>=97 && s<=122)
	s = s-32;
	return s;
}
char lower_to_upper(char s)
{
	if(s>=65 && s<=90)
	s = s+32;
	return s;
}
