#include<stdio.h>
int main()
{
	unsigned int a=20;
	unsigned int m=1,i,pos=4,res;
	m=m<<(pos-1);
	for(i=m;i>0;i=i/2)
	{
		res=a&i;
		if(res==0)
			printf("0");

		else

			printf("1");
	}
}
