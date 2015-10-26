#include"stdio.h"
int main()
{
	int n=5,i,j,p,s=0,t,t1,x,y;
	for(i=0;i<=n;i++)
	{
		t=get_factorial(x+i);
		//printf("%d\n",t);
	}
	for(j=0;j<=n;j++)
	{
		t1=get_factorial(y+j);
		//printf("%d\n",s);
		p=t/t1;
	}
	s=s+p;
	printf("sum of is:%d\n",s);
}
int get_factorial(int n)
{
	int f=1,o;
	for(o=1;o<=n;o++)
		f=f*o;
	return(f);
}



