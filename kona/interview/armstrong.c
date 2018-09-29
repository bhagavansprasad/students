#include <stdio.h>
main()
{
	int a=371,c,d=a,s=0;
	while(a!=0)
	{
		c=a%10;
		a=a/10;
		s=s+c*c*c;
	}
	if(s==d)
	printf("armstrong\n");
	else
	printf("not armstrong\n");
}
