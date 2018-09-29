#include <stdio.h>
#pragma pack(2)
struct SIZE{
	int i;
	char ch;
	double db;
}a;
main()
{
//printf("%d",sizeof(struct SIZE));
printf("%d",sizeof(a));
}
