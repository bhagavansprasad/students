#include <stdio.h>
#include <string.h>

main()
{
	char msg = 'B';
	char buff[26]={'A','B','C'};
	char buff1[26]={'Z','Y','X'};
	int i;
	for(i=0; i <= 26; i++)
	{
		if(buff[i] == msg)
		{
			printf("%c\n",buff1[i]);
		}
	}
}
