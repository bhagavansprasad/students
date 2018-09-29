#include <stdio.h>
#include <string.h>
int main(void)
{
	char ch='S';
	int flag = 0;

	if (flag == 0)
	{
		//printf ("enter a character");
		//scanf("%c",&ch);

		if (ch>='A' && ch <='Z')
		{
			printf ("the character is already upper case\n");
		}
		else if (ch>='a' && ch <='z')
		{
			// A== 0x41 (in ascii) == 0100 0001
			ch|=32; // 32 is 0x10 == 0010 0000
			// ch |= ( 1<< 5);
			// ch+=32;
			// 'a' == 0x61 == 0110 0001
			printf ("the charater in upper case is %c\n",ch);
		}
		else if (ch >='0' && ch<='9')
		{
			flag = 1;
		}
		else
		{
			printf ("the input was not a character");
		}
	}
	return 0;
} 
