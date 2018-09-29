#include <stdio.h>
#include <stdlib.h>
struct dat
{
	char a;
	int b;
};
typedef struct
{
	char a:3;
	int b:6;
	//struct dat d2;
}data;

int main()
{
	data d1;
	sleep(5);
	printf("sizof of d1 -> %d\n", sizeof(d1));
	return 0;
}
