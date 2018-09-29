#include <stdio.h>
int a_strncasecmp(char *,char *,int );	
char upper_to_lower(char );
char lower_to_upper(char );
main()
{
	int n=17;
	char *str="IAM MANOHAR reddy";
	char *ptr="IAM manohar REDDY";
	a_strncasecmp(str,ptr,n);	
}
int a_strncasecmp(char *str,char *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
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

