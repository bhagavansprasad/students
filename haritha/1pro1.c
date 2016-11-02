#include<stdio.h>
main(int argc,char*argv[])
{
	int m,n,j,neg,t,c[2]={0,0},i=0,k=0;
	int add (int x,int y);
	int sub(int x,int y);
	int mul (int x,int y);
	int div(int x,int y);
	int mod(int x,int y);
	for(j=2;j<argc;j++)
	{
		for(i=0;(argv[j]+i)!='\0';i++)
		{
			m=*(argv[j]+i);
			n=atoi(m);
			if(n>=0&&n<=9)
			{
				c[k]=(c[k]*10+n);
			}
			else
			{
				neg=1;
			}
		}
		if(neg==1)
		{
			c[k]=0-c[k];
		}
		k++;
		neg=0;
	}
}
if(strcasecmp(argv[1],"ADD")==0)

{
	t=add (c[0],c[1]);
	printf("%d",t);
}
if(strcasecmp(argv[1])=="sub")
{
	t=sub(c[0],c[1]);
	printf("%d",t);
}
if(strcasecmp(argv[1])=="mul")
{
	t=mul(c[0],c[1]);
	printf("%d",t);
}
if(strcasecmp(argv[1])=="div")
{
	t=div(c[0],c[1]);
	printf("%d",t);
}
if(strcasecmp(argv[1])=="mod")
{
	t=mod(c[0],c[1]);
	printf("%d",t);
}
int add(int x,int y)
{
	int z;
	z=x+y;
	return z;
}
int sub(int x,int y)
{
	int z;
	z=x-y;
	return z;
}
int mul(int x,int y)
{
	int z;
	z=x*y;
	return z;
}
int div(int x,int y)
{
	int z;
	z=x/y;
	return z;
}
int mod(int x,int y)
{
	int z;
	z=x%y;
	return z;
}



