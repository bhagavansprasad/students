#include<stdio.h>
main()
{
	int a=626,b,rev=0;
	rev=(rev*10)+(a%10);
	a=a/10;
	rev=(rev*10)+(a%10);
	a=a/10;
	rev=(rev*10)+(a%10);
	printf("%d\n", rev);
	printf("%d\n", a);
	b = rev;
	if(b==626)
		printf("palindrome\n");
	else
		printf("no palindrome\n"); 
}
