#include <stdio.h>
#include <string.h>
#pragma pack(1)
struct student
{
	int a;
	int b;
	char c;
	short int d;
	float e;
};
main()
{
	int i=0;
	struct student s1={300,400,'Z',500,6.1};
	char *cp;
	cp=&s1;
	printf("valve of a== %d\n",s1.a);
	printf("valve of b== %d\n",s1.b);
	printf("valve of c== %d\n",s1.c);
	printf("valve of d== %d\n",s1.d);
	printf("valve of e== %f\n",s1.e);
	printf("address of a== %u\n",&s1.a);
	printf("address of b== %u\n",&s1.b);
	printf("address of c== %u\n",&s1.c);
	printf("address of d== %u\n",&s1.d);
	printf("address of e== %u\n",&s1.e);
	for(i=0;i<sizeof(s1);i++)
	{
		printf("adress of each byte==%u\t and value==%d\n",cp,*cp);
		cp++;
	}
	printf("size of structure==%d\n",sizeof(s1));
}
