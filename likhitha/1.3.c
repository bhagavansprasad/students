#include <stdio.h>
int main()
{
	int a=616,b=0,c=a;
	b=(b*10)+(a%10);
	a=a/10;

	b=(b*10)+(a%10);
	a=a/10;

	b=(b*10)+(a%10);
	a=a/10;
	if(c==b)
		printf("%d is palindrome \n",b); 
	else
		printf("given num is not palindrome\n");

}


