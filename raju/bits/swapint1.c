#include<stdio.h>

#define GET_BIT_VALUE(n,pos) ((n)&(1<<(pos)-1)?1:0)

#define SET_BIT_VALUE(n,pos,value) \
value==1?((n)=(n)|(1<<(pos)-1)):((n)=(n)&(~(1<<pos-1)));

main()
{
	
	int a=4,b=2,ta,tb,i;

	for(i=1;i<=32;i++)
	{
		
		ta=GET_BIT_VALUE(a,i);

		tb=GET_BIT_VALUE(b,i);

		printf("ta:%d\t tb:%d\n",ta,tb);

		if(ta!=tb)
		{
			
			SET_BIT_VALUE(a,i,tb);
			
			SET_BIT_VALUE(b,i,ta);

			printf("if ta:%d\t if tb:%d\n",ta,tb);
			printf("if a:%d\t if b:%d\n",a,b);

		}
	}	

	printf("a:%d\t b:%d\n",a,b);

}	

