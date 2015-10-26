#include <stdio.h>
int main(int argc,char *argv[])
{
	int a=-1,b=1,c,count=1,i;
	 int n = atoi(argv[1]);
	for(i=1;count<=n;i++)
	{
	c = a+b;
	a=b;
	b=c;
	printf("%d ",c);
	count ++;
	}
	printf("\n");
}
