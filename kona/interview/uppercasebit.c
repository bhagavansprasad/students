#include <stdio.h>
int main(void)
{
	char ch='a';
	int flag = 0;

	if (flag == 0)
	{
		if (ch>='A' && ch <='Z')
		{
			printf ("the character is already upper case\n");
		}
		else if (ch>='a' && ch <='z')
		{
			ch|=32; 
			printf ("the charater in upper case is %c\n",ch);
		}
		else if (ch >='0' && ch<='9')
		{
			flag = 1;
		}
		else
		{
			printf ("the input was not a character\n");
		}
	}
	return 0;
} 
