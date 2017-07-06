#include <stdio.h>

main()
{

	int result, n = 10,temp[6] = {0}, pos = 0;
	while(n > 0)
	{
		 n= n >> (pos);
		temp[pos] = 1 & n;
		pos++;
	}

	for(pos = 3; pos >= 0; pos--)
		printf("%d\n", temp[pos]);
}
