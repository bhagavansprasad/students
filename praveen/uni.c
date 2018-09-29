#include <stdio.h>
union std
{
	int a;
	int b;
	char c[3];
	short int d;
};
union std abc;

main()
{
	abc.a=0x121314;
	printf("%x\n",abc.a);
	printf("%x\n",abc.c[0]);
	printf("%x\n",abc.c[1]);
	printf("%x\n",abc.c[2]);
	printf("%x\n",abc.c[3]);
}
