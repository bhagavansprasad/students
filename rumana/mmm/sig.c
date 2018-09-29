#include<stdio.h>
char buff[300];
int f[3]={0};
void* amalloc(int);
char *p[3];
main()
{
	char *p1[3];
	p[0]=&buff;
	printf("p[0] is %u\n",p[0]);
	p[1]=&buff[100];
	printf("p[1] is %u\n",p[1]);
	p[2]=&buff[200];
	printf("p[2] is %u\n",p[2]);
	p1[0]=amalloc(100);
	printf("p1[0] is %u\n",p1[0]);
	p1[1]=amalloc(100);
	printf("p1[1] is %u\n",p1[1]);
	p1[2]=amalloc(100);
	printf("p1[2] is %u\n",p1[2]);
}


void* amalloc(int size)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			return ((void *)p[i]);
		}
	}
	return NULL;
}
