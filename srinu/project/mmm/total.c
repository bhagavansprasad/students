#include <stdio.h>
main()
{
	int a[3][2]={
					{100,2},
					{200,3},
					{300,4}
				};
	char *p1[9];
	int i,size=0;
	for(i=0;i<3;i++)
	{
		size=size+(a[i][0]*a[i][1]);
	}
	printf("size value is %d\n",size);
	char *p;
	p=malloc(size);
	printf("p vlaue is %u\n",p);
	p1[0]=p;
	printf("value of p1[0] is %u\n",p1[0]);
	p1[1]=&p[100];
	printf("value of p1[1] is %u\n",p1[1]);
	p1[2]=&p[200];
	printf("value of p1[2] is %u\n",p1[2]);
	p1[3]=&p[400];
	printf("value of p1[3] is %u\n",p1[3]);
	p1[4]=&p[600];
	printf("value of p1[4] is %u\n",p1[4]);
	p1[5]=&p[900];
	printf("value of p1[5] is %u\n",p1[5]);
	p1[6]=&p[1200];
	printf("value of p1[6] is %u\n",p1[6]);
	p1[7]=&p[1500];
	printf("value of p1[7] is %u\n",p1[7]);
	p1[8]=&p[1800];
	printf("value of p1[8] is %u\n",p1[8]);
}
