#include <stdio.h>
int main()
{
	unsigned int a = 0x21232420 ,i=0;
	char *cp = &a;
	if(*cp==0x20)
	{
		printf("little endian machine\n");
	}
	else
	{
		printf("big endian machine\n");
	}
	for(i=0;i<4;i++)
	{
		printf("%u == %x\n",cp,*cp);
		cp++;
	}
}
