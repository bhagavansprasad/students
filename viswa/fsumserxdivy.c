#include<stdio.h>
main()
{
	int n=5,x=3,y=2,t,sum=0,i;
	for(i=1;i<=n;i++)
	{
		t=((f_sum_x_div_y(x+i))/(f_sum_x_div_y(y+i)));
		sum+=t;
	}
	printf("%d",sum);
}
int f_sum_x_div_y(int z)
{
	int f=1,j;
	for(j=1;j<=z;j++)
	{
		f*=j;
	}
	return(f);
}
