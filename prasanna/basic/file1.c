#include<stdio.h>
int func();
int i=10;

main()
{
	func();
	i=100;
	printf("I----> %d\naddress---> %u\n",i, &i);
}
