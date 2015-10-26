#include<stdio.h>

char *astr_char(char *str,char ch)
{
	
	while(*str++ !='\0')
	{
	  if(*str==ch)
		return str;
	//  str++;
	}
	return NULL;
}	

main()
{
	char str[30] ="prasanna kumar s yadravi";
	
	printf(" %s\n",astr_char(str,'k'));
}	
