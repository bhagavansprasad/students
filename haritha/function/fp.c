#include <stdio.h>
int add(int a,int b);
int sub(int a,int b);
int mul(int a,int b);
int div(int a,int b);
main()
{
	int a=5,b=6,i;
	int (*p[])(int,int)={add,sub,mul,div};
	char *q[]={"add","sub","mul","div"};
	for(i=0;i<4;i++)
	printf("%s\t%d\n",q[i],(*p[i])(a,b));
		return 0;
	
}
int add (int a,int b)
{
	return a+b;
}
int sub (int a,int b)
{
	return a-b;
}
int mul (int a,int b)
{
	return a*b;
}
int div (int a,int b)
{
	return a/b;
}
