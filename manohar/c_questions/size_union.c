#include <stdio.h>
union list
{
	int pid;
	char data;
}num;
int main()
{
	printf("union size is--->%d\n",sizeof(num));
}
