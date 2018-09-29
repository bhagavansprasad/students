#include <stdio.h>
#include <stdbool.h>
main()
{
	char a[3];
	a[0]=0x034b0;
	int i,n,mask=1;
	bool f;
	for(i=31;i>=0;i--)
	{
		n = (a[0]&(mask<<i));
		if(n==0)
		printf("0");
		else
		printf("1");
	}
	
	f = (a[0]&0xf0)>>4;
	printf("%d\n",f);

}
