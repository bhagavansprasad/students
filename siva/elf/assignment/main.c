#include "amalloc.h"
int gv = 0;

int func1();
int func2();

int func1()
{
	int *p;
	printf("Enter Function 1 : \n");
	p = amalloc(40);
	afree(p);
	printf("Returned Function 1 : \n");
	return 0;
}

int func2()
{
	int *p2;
	printf("Enter Function2 : \n");
	p2=amalloc(200);
	if(gv == 2)
	{
		afree(p2);
	}
	printf("Returned Function 2 : \n");
	return 0;
}

main()
{
	printf("Enter the Main :\n");
	func1();
	func2();
	display_node();
	printf("Returned Main :\n");
}

