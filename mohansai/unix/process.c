#include "stdio.h"
main()
{
	int i = 0;

	for( ; ;i++ )
	{
		if(i == 999999999)
		{
			i = 0;
			sleep(1);
		}
	}
}
