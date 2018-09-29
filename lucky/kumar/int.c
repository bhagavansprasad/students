#include<stdio.h>
main()
{
	int a=0x12131415,i=0;
	char*cp=&a;
	*(cp+3)=0;
	for(i=0;i<4;i++)
	{
		printf("%x",*cp);
		cp++;
	}
}
