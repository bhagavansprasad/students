#include <stdio.h>
main()
{
	int a=1101,p=1,d,s=0,k;
	while(a!=0)
	{
		k=a%10;
		d=k*p;
		s=s+d;
		p=p*2;
		a=a%10;
		printf("%d",s);
	}
}
