#include <stdio.h>
#include <stdlib.h>
void *amalloc(int);
void afree(void *p2);
char a[100];
int flag = 0;
main()
{
	char *p ;
	p = amalloc(100);
	printf("--> %u\n",p);
	p = amalloc(100);
	printf("--> %u\n",p);
	printf("--> freeing \n");
	afree(p);
	p = amalloc(100);
	printf("--> %u\n",p);
	p = amalloc(100);
	printf("--> %u\n",p);
	afree(p);
	afree(p);
}

void *amalloc(int size)
{
	if(flag == 0)
	{
		flag =1;
		return (void *)a;
	}
	else 
		return NULL;
}

void afree(void *p2)
{
	if(flag==1)
	{
	flag = 0;
	}
	else
	  printf("error message\n");


}

