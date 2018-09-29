#include <stdio.h>
int main()
{
	char a_strlwr(char ch);
	char strs[][100]={
		"AURA",
		"ara",
		"lEvEl",
		"nEt Of woRks 123 GooD",
		"121",
		"123RE4",
		"123a21",
		"121345yEs",
		"networks"
	};
	int i,j;
	printf("Lower case\n");
	for(i=0;i<sizeof(strs)/sizeof(strs[0]);i++)
	{
	for(j=0;strs[i][j];j++)
	{
		a_strlwr(strs[i][j]);
		printf("%c")
	}
	printf("-->%d %s\n",i+1,strs[i]);
	}
	return 0;
}
