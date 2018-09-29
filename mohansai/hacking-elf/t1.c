#include "stdio.h"

int my_var = 1234;

int first_function(void)
{
	printf("-->%s - my_var :%x\r\n", __FUNCTION__, my_var);

	return 0;
}

main()
{
	printf("-->%s - my_var  :%x\r\n", __FUNCTION__, my_var);
	
	first_function();
}
