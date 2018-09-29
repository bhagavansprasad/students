#include<stdio.h>
void fun1();
void fun2();

void fun1()
{
	static int i=1;      
	printf("fun1 i   :%d\n",i);
	i++;
	printf("fun1 i++ :%d\n",i);
}
void fun2()
{
	static int i; 
	i=5;
	printf("fun2 i   :%d\n",i);
	i++;
	printf("fun2 i   :%d\n",i);
}

int main()
{
	fun1();
	fun1();
	fun2();
	fun2();
}
