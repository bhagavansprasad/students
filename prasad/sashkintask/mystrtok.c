#include"stdio.h"
#include"stdlib.h"
#include"string.h"


int main()
{
	char str[]="16:13:31.23228600 L1R1TS31SC0 ECHO          MSG";
	char *str1;
	int x=1;

	printf("print string before parsing:%s\r\n",str);

	str1 = strtok(str, ":. ");

	printf("i=%d and str1=%s\r\n",x,str1);

	while(1)
	{
		str1 = strtok(NULL, ":. ");

		if(str1 == NULL)
		{
			printf("Tokenizing complete\r\n");
			exit(0);
		}

		printf("i=%d and str1=%s\r\n",x,str1);
		x++;
	}
	return 0;
}
