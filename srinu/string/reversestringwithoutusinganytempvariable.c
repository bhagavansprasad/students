#include<stdio.h>
#include <string.h>
int main()
{
	char str[10]="sreenu";
	int i,n=6;
	for(i = 0 ; i < n/2 ; i++)
 {
	str[i] = str[i] - str[n-1-i];
	str[n-1-i] = str[n-1-i] + str[i];
	str[i] = str[n-1-i] - str[i];
 }
	printf("%s\n",str);
}
