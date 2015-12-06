#include<stdio.h>

#define SWAP_INT(m,n,pos)  \
	((m)&(1<<((pos)-1))) == ((n)&(1<<((pos)-1)))?1:(((m)=(m)^1<<(pos)-1) , ((n)=(n)^1<<(pos)-1))

main()
{
   int a=215,b=285,i,r;

	for(i=1; i <= 16; i++)
	{
		r=SWAP_INT(a,b,i);
	
		printf("a:%d\t b:%d\t i:%d\t r:%d\n",a,b,i,r);
		
	}	

	printf("a:%d\t b:%d\n",a,b);
}

