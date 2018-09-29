#include<stdio.h>
void  my_copy_string_function(char*, char*);
main()
{
	char str1[10]="paidi";
	char str2[10]="kumar";
	int target;
	my_copy_string_function(str1 , str2);
	printf("copy string--->=%s\n",str2);
}
void my_copy_string_function(char *str1, char *str2)
{
	while(*str1)
	{
		*str2 = *str1;
		str1++;
		str2++;
	}
	*str2 = '\0';
}


