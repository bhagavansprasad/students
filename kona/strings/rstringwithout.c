#include <stdio.h>
#include <string.h>
main()
{
	char str[10]="hello";
	int i,n=5;
	for(i = 0 ; i < n/2 ; i++)
{
str[i] = str[i] - str[n-1-i];
str[n-1-i] = str[n-1-i] + str[i] ;
str[i] = str[n-1-i] - str[i];

}
printf("%s\n",str);
}
