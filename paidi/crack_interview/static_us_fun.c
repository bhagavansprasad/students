#include <stdio.h>
void main()
{
	static int var = 5;
	int *result;
	result  = &var;
	printf("%d\n",var--);
	if(var)
	{
		main();
	}
}
