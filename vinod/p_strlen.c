#include <stdio.h>
#include "a_string.h"
int main()
{
	char strs[][100]={
		"aura",
		"ara",
		"level",
		"net of works 123",
		"121",
		"1234",
		"12321",
		"121345",
		"networks"
	};
	int len,i;
	for(i=0 ; i<sizeof(strs)/sizeof(strs[0]) ; i++)
	{
	len = a_strlen(strs[i]);
	printf("-->%d length of %s is %d\n",i+1,strs[i],len);
	}
	return 0;
}
