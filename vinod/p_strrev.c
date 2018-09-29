#include<stdio.h>
#include "a_string.h"
int main()
{
	char a[]="AniL";
	printf("Before rev string a --> %s\n",a);
	a_strrev(a);
	printf("After rev string b --> %s\n",a);
	return 0;
}
