#include <stdio.h>
char buf[300];
int flag[3]={0};
	char *p[2];
void *amalloc(int size );
main()
{
	char *p1[2];
	p[0]=&buf;
	printf("%u\n",p[0]);
	p[1]=&buf[100];
	printf("%u\n",p[1]);
	p[2]=&buf[200];
	printf("%u\n",p[2]);
	p1[0]=amalloc(100);
	printf("first p1[0] value is %u\n",p1[0]);
	p1[1]=amalloc(100);
	printf("first p1[1] value is %u\n",p1[1]);
	p1[2]=amalloc(100);
	printf("first p1[2] value is %u\n",p1[2]);
}
void *amalloc(int size )
{
	int i;
	for(i=0;i<3;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			return(void *)p[i];
		}
	}
	return NULL;
}
