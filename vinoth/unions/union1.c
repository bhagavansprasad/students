#include "stdio.h"
union student
{
	int i;
};
	//union student b;

main()
{
	union student b;
	int j;
	b.i=300;
	char *c=&b;
	for (j=3; j>=0; j--,c++)
	{
		printf ("%d\n", *c);
	}
}
