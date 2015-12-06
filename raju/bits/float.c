#include<stdio.h>

#define GET_BIT_VALUE(n,pos,p) ((n)&(p<<(pos)-1)?1:0)

main()
{

	float a=2.5;
	int i,t,p=1;
	char *ptr;
	ptr=&a;

	/*for(i=32;i>=1;i--)
	{

		t=GET_BIT_VALUE(a,i,p);

		printf("t:%d",t);

	}

	printf("\n");*/

	for(i=3;i>=0;i--)
	{
	
		printf("a:%f\n",*(ptr+i));
	}

printf("%f\n",*ptr);
}	

