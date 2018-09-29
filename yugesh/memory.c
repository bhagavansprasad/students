#include <stdio.h>
#include <stdlib.h>
void *amalloc(int size);
void afree();
char buff1[100];
char buff2[100];
int flag1=0;
int flag2=0;
main()
{
	char *p1,*p2;
	p1=amalloc(100);
	printf("-------> %u\n",p1);
	p1=amalloc(100);
	printf("-------> %u\n",p1);
//	afree(p1);
	p2=amalloc(100);
	printf("-------> %u\n",p2);
	afree(p2);
	afree(p1);
	p2=amalloc(100);
	printf("-------> %u\n",p2);
	p2=amalloc(100);
	printf("-------> %u\n",p2);
}
void *amalloc(int size)
{
	if(flag1==0)
	{
		flag1=1;
		return (void *)buff1;
	}
	else if(flag2==0)
	{
	flag2=1;
	return (void *)buff2;
	}
	else
	 return NULL;
}
void afree()
{
    flag1=0;
	flag2=0;
}
