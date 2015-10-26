#include<stdio.h>
main()
{
	int a=0x12131415,i,k,j,l=0;
	char *p;
	p=&a;
	for(i=0;i<=3;i++,p++)
		printf("%x",*p);
	for(k=0;k<=3;k++)
	{
		printf("\n");
		for(i=3;i>=0;i--,j++)
		{
			p=(char *)&a+i;
			j=k;
			if(i==j)
				printf("%x",l);
			else
				printf("%x",*p);
		}
	}
}
