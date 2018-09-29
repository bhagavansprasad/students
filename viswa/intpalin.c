#include<stdio.h>
main()
{
	int a=636;
	int c=0,x;
	x=a;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	if(x==c)
		printf("palindrome");
	else
		printf("not palindrome");
}
