#include <stdio.h>
#include <stdlib.h>
char buf[100];
int flag=0;
void* amalloc(int size);
void afree(void *p1);
main()
{
	char *p1;
	p1=amalloc(100);
	printf("--->%u\t",p1);
	p1=amalloc(100);
	printf("--->%u\t",p1);
	printf("---> freeing \n");
	afree(p1);
	p1=amalloc(100);
	printf("--->%u\t",p1);
	p1=amalloc(100);
	printf("--->%u\t",p1);
	afree(p1);
	afree(p1);
}
void* amalloc(int size)
{
	if(flag==0)
	{
		flag = 1;
		return (void *)buf;

	}
	else 
		return NULL;
}
void afree(void *p1)
  {
  	flag=0;
  }
