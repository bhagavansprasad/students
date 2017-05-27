#include <stdio.h>
int main()
{
	int a=0x134201;
	char *p=(char*)&a;
	if(*p==0x01)
		printf("little endian\n");
	else
		printf("big endian\n");
}
