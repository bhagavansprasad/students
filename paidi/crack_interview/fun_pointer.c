#include <stdio.h>
int display();
int (*fp)();
int main()
{
	fp = display;
	(*fp)();
}

int display()
{
	printf("Hello World \n");
}
