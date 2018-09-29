#include <stdio.h>

void call_hello(void (*fptr)(void));
static void hello(void)
{
	puts("hello");
}

int main(void)
{
	void (*fptr)(void) = hello;
	call_hello(fptr);
	return 0;
}
