#include <stdio.h>
main()
{
	int i,mask,count=0,n=1024;
	for(i=0;i<32;i++)
	{
		mask=1<<i;
		if((n&mask)!=0)
		count++;
	}
	if(count ==1)
	printf("power of 2\n");
	else
	printf(" not power of 2\n");

}
