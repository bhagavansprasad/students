#include <stdio.h>
int fun1(int x ,int y)
{
	return x+y;
}
 
void fun2(int (*fptr)(int,int));
int main()
{
	//int x = 10, y = 20;
	int (*fptr)(int,int) = fun1;
	fun2(fptr);
	return 0;
}

