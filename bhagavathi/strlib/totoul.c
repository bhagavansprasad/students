#include<stdio.h>
int atolower(int *a);
//int atoupper(int *a);
	r1=atolower(s1[0]);																		//10
	printf("given string changed lower:%s\n\n",s1);

	r2 = atoupper(s1[1]);																		//11
	printf("given string changed upper :%s\n\n",s1);

atolower.o:atolower.c
	gcc atolower.c -c

atoupper.o:atoupper.c
	gcc atoupper.c -c

