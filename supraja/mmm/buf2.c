#include <stdio.h>
#include <stdlib.h>
void *amalloc(int);
void afree(void *p2);
char a[100],b[100];
int flag1 = 0,flag2=0;
main()
{
	char *p1 ;
	char *p2;
	p1 = amalloc(100);
	printf("-->1 allocation: %u\n",p1);
	p2 = amalloc(100);
	printf("--> 2 allocation :%u\n",p1);
//	printf("--> freeing \n");
	afree(p1);
	p1 = amalloc(100);
	printf("--> 3 allocation :%u\n",p1);
	afree(p1);
//	p1 = amalloc(100);
//	printf("-->4 allocation: %u\n",p1);
//	afree(p1);
	afree(p1);
}

void *amalloc(int size)
{
	if(flag1 == 0)
	{
		flag1 =1;
		return (void *)a;
	}
	else if(flag2 == 0)
	{
		flag2 =1;
		return (void *)b;
	}
	else
	return NULL;
}

void afree(void *n2)
{
	if(flag1==1&&n2==a)
	{
	flag1 = 0;
	}
	else if(flag2==1&&n2=b)
	{
	flag2 = 0;
	}
	else
	  printf("error message\n");


}

