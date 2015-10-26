#include<stdio.h>
main()
{
	int a=10,b=5;
	int *ptr=&b;
	int iarr1[10];
	int iarr2[10]={1,2,3};
	char carr1[10];
	char carr2[128]="Aura Networks";
	char *cptr="Aura Networks";
	short sharr1[10];
	short sharr2[10]={5,6};

/*	printf("a:%p\n",a);
	printf("a:%d\t, %x\n",&a,&a);*/

	printf("ptr:%p\t,%d\t,%x\n",ptr,ptr,ptr);
	printf("&ptr:%p\t, %d\t ,%x\n",&ptr,&ptr,&ptr);
	printf("*ptr:%p\t,%d\t,%x\n",*ptr,*ptr,*ptr);







}	

