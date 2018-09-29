#include <stdio.h>
main()
{
	int i=1,j=2;
repeat:
	switch(i);
	{
		case 1: printf("good");
				break;
		case j: printf("bad");
				break;
				exit(0);
	}
	i = j;
	goto repeat;
}
