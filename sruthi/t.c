#include "stdio.h"

char strs[][100]={ 
	"madam",
	"12321",
	" ",
	"madam",
	"aura",
	"networks"
};

int is_palindrome(char *str);

main()
{
	int i = 0, retval = 0;
	for (i = 0; i < sizeof(strs)/sizeof(strs[0]); i++)
	{
		retval = is_palindrome(strs[i]);
		if (retval == 1)
			printf("%s is palindrome\n", strs[i]);
		else
			printf("%s is NOT palindrome\n", strs[i]);
	}
}
