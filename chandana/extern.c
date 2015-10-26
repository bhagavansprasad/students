#include <stdio.h>
int fun()
{
extern  int i;
	i=10;

	printf("fun() : %d\n",i);
	i=20;
	printf("fun() : %d\n",i);
}


int main()
{
//	extern int i;
	fun();

extern int	i;
i =30;

	printf("%d\n",i);
	fun2();

}
int i;
int fun2()
{
extern  int i;
	i=10;

	printf("fun2() : %d\n",i);
	i=20;
	printf("fun2() : %d\n",i);
}




