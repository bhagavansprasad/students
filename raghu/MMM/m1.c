#include <stdio.h>
int flag=0;
char buff[100];

void * amalloc(int size);
void afree(void * p1);

main()
{
	int *p1,*p2;
	p1 = amalloc(100);
	printf("the p1 valu is %u\n",p1);
	p2 = amalloc(100);
	printf("the p2 valu is %u\n",p2);

	afree(p1);
	
}

void * amalloc(int size)
{
	if(flag == 0)
	{
		flag = 1;
		return buff;
	}
	else
	return NULL;
}

void afree(void * p1)
{
	if(flag == 1)
	{
		flag = 0;
	}

}
