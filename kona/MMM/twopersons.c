#include <stdio.h>
char buf[10][100];
int flag[10]={0};
void* amalloc(int size);
void afree();
main()
{
	 char *p1[10],*p2[10];
	 int i;
	 for(i=0;i<10;i++)
	 {
	 	printf("%u\n",buf[i]);
	}
	p1[0]=amalloc(100);
	printf(" first time p1[0] vlaue--->%u\n",p1[0]);
	p1[1]=amalloc(100);
	printf("first time p1[1] value--->%u\n",p1[1]);
	printf("---> freeing \n");
	p2[0]=amalloc(100);
	printf("first time p2[0] value--->%u\n",p2[0]);
	afree(p1[1]);
	p2[0]=amalloc(100);
	printf("second time p2[0] value--->%u\n",p2[0]);
	afree(p1[0]);
	p2[1]=amalloc(100);
	printf("firstime p2[1] value--->%u\n",p2[1]);
	afree(p2[0]);
	p1[0]=amalloc(100);
	printf("secnod time p1[0] value--->%u\n",p1[0]);
	afree(p1[0]);
	afree(p1[1]);
	//afree(p1[1]);
	printf("p1[0] value is %u\n",p1[0]);
	printf("secnod time p1[0] value--->%u\n",p1[0]);
}
void* amalloc(int size)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(flag[i]==0)
		{
			flag[i] = 1;
			return (void *)buf[i];
		}
	}
		return NULL;
}
void afree(void *p)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(p==buf[i])
		{
			flag[i]=0;
		}
	}
		printf("no memory \n");
}

