#include <stdio.h>
#include <stdlib.h>
char buf1[100],buf2[100];
int flag1=0,flag2=0;
void* amalloc(int size);
void afree();
main()
{
    char *p1[2],*p2[2];
	p1[0]=amalloc(100);
	printf(" first time p1 vlaue--->%u\n",p1[0]);
	p1[1]=amalloc(100);
	printf("second time p1 value--->%u\n",p1[1]);
	printf("---> freeing \n");
	p2[0]=amalloc(100);
	printf("first time p2 value--->%u\n",p2[0]);
	afree(p1[0]);
	p2[1]=amalloc(100);
	printf("second time p2 value--->%u\n",p2[1]);
	afree(p1[1]);
	p1[1]=amalloc(100);
	printf("thrid time p1 value--->%u\n",p1[1]);
	afree(p1[1]);
	printf("fourth  time p1 value--->%u\n",p1[1]);
	afree(p2[1]);
	afree(p1[1]);
	afree(p1[0]);
	afree(p2[0]);
	printf("fifth  time p1 value--->%u\n",p1[1]);
}

void* amalloc(int size)
{
	if(flag1==0)
	{
		flag1 = 1;
		return (void *)buf1;
	}
	else if (flag2==0)
	{
		flag2=1;
		return (void *)buf2;
	}
	else 
		return NULL;
}
void afree(void *p)
{
	if(p==buf1)
	{
	flag1=0;
	}
	else if(p==buf2)
	{
	flag2=0;
	}
	else
	{
		printf("no memory \n");
	}
}
