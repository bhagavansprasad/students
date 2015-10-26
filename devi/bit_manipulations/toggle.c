#include <stdio.h>
void toggle(int a,int pos)
{
	int mask = 1,n;
	a = (a^(mask<<pos));
	printf("%d\n",a);
	if(n == 0)
	printf("0");
	else
	printf("1");
}

main()
{
	int a = 10,pos = 1;
	toggle(a,pos);
}
