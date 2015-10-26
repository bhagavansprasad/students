#include <stdio.h>
main()
{
	char strs[][100]={
		"aura",
		"ara",
		"level",
		"net",
		"121",
		"1234",
		"12321",
		"121345",
		"networks"
	};
	int i,flag=0;
	for(i=0;i<sizeof(strs)/sizeof(strs[0]);i++)
	{
	flag=is_palindrome(strs[i]);
	if(flag==1)
		printf("%s is palindrome\n",strs[i]);
	else
		printf("%s is not palindrome\n",strs[i]);
	}
}
