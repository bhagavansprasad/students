#include <stdio.h>
#include <string.h>
struct student
{
	char a;
	char b;
	int c;
	//short int d;
};
int main()
{
	int i;
	int size = 6;
	struct student s1 = {0};
	char *cp=&s1;
	printf("expected size of structure == %d\n",size);
	printf("size of structure in bytes == %d\n\n",sizeof(s1));
	printf("adress of a == %u\n",&s1.a);
	printf("adress of b == %u\n",&s1.b);
	printf("adress of c == %u\n",&s1.c);
	//printf("adress of d == %u\n\n",&s1.d);
	for(i=1;i<=sizeof(s1);i++)
	{
		printf("adress of variable in %dth byte is == %u\n",i,cp);
		cp++;
	}

}
