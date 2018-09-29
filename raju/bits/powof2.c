#include<stdio.h>

#define GET_BIT_VALUE(n,pos) ((n)&(1<<(pos)-1)?1:0)

main()
{

	int a=65,t,i,count=0;

	for(i=1;i<=8*sizeof(a);i++)
	{

		t=GET_BIT_VALUE(a,i);

		if(i==1 && t==1)
			break;

		if(t==1)
			count++;

	}		

	if(count==1)
		printf("%d is power of 2\n",a);
	
	else
		printf("%d is not power of 2\n",a);

}

