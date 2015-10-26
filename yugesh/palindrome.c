#include <stdio.h>
main()
{
	int a=626,c=0,temp=a;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	if(temp==c)
		printf("yes,because reverse of 626 is also 626\n");
	else
		printf("not a polindrome");
}
