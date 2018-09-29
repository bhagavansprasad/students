#include<stdio.h>
void* amalloc(int);
void afree(void*);
char buff[3][100];
int flag[3]={0,0,0};
main()
{
	char *p[3],*q[3];
	int i;
	for(i=0;i<3;i++)
		printf(" buff[i] is %p\n",buff[i]);
	p[0]=amalloc(100);
	printf("p[0] is %p\n",p[0]);
	p[1]=amalloc(100);
	printf("p[1] is %p\n",p[1]);
	p[2]=amalloc(100);
	printf("p[2] is %p\n",p[2]);
	q[0]=amalloc(100);
	printf("q[0] is %p\n",q[0]);
	afree(p[2]);
	q[1]=amalloc(100);
	printf("q[1] is %p\n",q[1]);
}
void* amalloc(int size)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			return ((void*)buff[i]);
		}
	}
	return NULL;
}
void afree(void* p)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(p==buff[i])
		{
			flag[i]=0;
			break;
		}
	}
}
