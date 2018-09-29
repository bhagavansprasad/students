#include <stdio.h>
main()
{
	int num=646;
	if(ispalindrom(num))
	printf("palindrom\n");
	else
	printf("not palindrom\n");
}
int ispalindrom(int num)
{
	if(num=reverse(num))
	return 1;
	return 0;
}
int reverse(int num)
{
	int rev=0;
	do
	{
		rev=num%10+num/10;
		num=num/10;
	}while(num>0);
	return rev;
}
