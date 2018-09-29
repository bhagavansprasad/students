#include<stdio.h>

#define REV_INT(n,spos,epos)  \
	((n)&(1<<((spos)-1))?1:0) == ((n)&(1<<((epos)-1))?1:0)?2:(((n)=(n)^1<<(epos)-1) ,((n)=(n)^1<<(spos)-1))

main()
{
    int a=9,r;
	int i,j;

	for(i=8,j=1; i > j; i--,j++)
	{
		r=REV_INT(a,i,j);
	printf("pi:%d\n",((a)&(1<<((i)-1))));

	
	printf("pj:%d\n",((a)&(1<<((j)-1))));


	
		printf("a:%d\t i:%d\t j:%d\t r:%d\n",a,i,j,r);
		
	}	

	printf("a:%d\n",a);
}

