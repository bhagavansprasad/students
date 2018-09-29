#include<stdio.h>
main()
{
	int i;
	int a=0x12131415;
	int b;
	char *x=(char *)&a;
	char *y=(char *)&b;
	for(i=0;i<4;i++)
		printf("%x\t",x[i]);
	y[0]=x[0];
	y[1]=x[1];
	y[2]=0;
	y[3]=x[3];
	for(i=0;i<4;i++)
		printf("%x\t",y[i]);
}

