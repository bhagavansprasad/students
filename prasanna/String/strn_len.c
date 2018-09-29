#include<stdio.h>
#include<string.h>

int strn_len(char *str,int maxlen)
{
	int n;
	char *e;
	
	for(e=str,n=0;*e && n < maxlen;e++,n++)
	;
	return n;
}

main()
{
	char str[100] = "My name is prasannakumar s yadravi";

	printf("length of string : %d\n",strlen(str));
	printf("length of string 2: %d\n",strn_len(str,15));

	
