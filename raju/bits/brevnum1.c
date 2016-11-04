#include<stdio.h>

#define GET_BIT_VALUE(n,pos) ((n)&(1<<(pos)-1)?1:0)

#define SET_BIT_VALUE(n,pos,value) \
value==1?((n)=(n)|(1<<(pos)-1)):((n)=(n)&(~(1<<pos-1)));

main()
{
	
	int a=10,ti,tj,i,j;

	for(i=4,j=1;i > j;i--,j++)
	{
		
		ti=GET_BIT_VALUE(a,i);

		tj=GET_BIT_VALUE(a,j);

		printf("ti:%d\t tj:%d\n",ti,tj);

		if(ti!=tj)
		{
			
			SET_BIT_VALUE(a,i,tj);
			
			SET_BIT_VALUE(a,j,ti);

			printf("if ti:%d\t if tj:%d\n",ti,tj);
			printf("if a:%d\n",a);

		}
	}	

	printf("a:%d\n",a);

}	

