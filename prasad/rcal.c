#include"stdio.h"
#include"rfuns.h"
int add(int a,int b)
{
	int l;
	l=a+b;
	printf("add=%d",l);
}

int mul(int a,int b)
{
	int l;
	l=a*b;
	printf("mul=%d",l);
}
int sub(int a,int b)
{
	int l;
	l=a-b;
	printf("sub=%d",l);
}
int div(int a,int b)
{
	float l;
	l=(float)a/b;
	printf("divi=%d",l);
}
struct data
{
	char name;
	int (*fun)(int,int);
}d[4]={{"add",add},
	{"mul",mul},
	{"sub",sub},
	{"div",din}};
main(int argc,char *argv[])
{
	int m,n,i;
	m=ratoi(argv[2]);
	n=ratoi(argv[3]);
	for(i=0;i<=3;i++)
	{
		if(rstrcmp(argv[1],d[i].name)==0)
		{
			fun=d[i].fun;
			fun(m,n);
		}
	}
}
