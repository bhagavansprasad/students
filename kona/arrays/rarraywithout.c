#include <stdio.h>
main()
{
	int str[10]={10,20,30,40,50};
	int i,n=5;
	for(i = 0 ; i < n/2 ; i++)
{
str[i] = str[i] - str[n-1-i];
str[n-1-i] = str[n-1-i] + str[i] ;
str[i] = str[n-1-i] - str[i];

}
for(i=0;i<n;i++)
printf("%d\n",str[i]);
}
