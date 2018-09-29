#include <stdio.h>
int main(int argc,char *argv[])
{
	int a=-1,b=1,c,i;
	 int n = atoi(argv[1]);
	for(i=1;i<=n;i++)
	{
	c = a+b;
	a=b;
	b=c;
	printf("%d ",c);
	}
	printf("\n");
}
