#include <stdio.h>
#include <string.h>
int pstrlen(char *s)
{
	int i;
	for(i=0;*s;i++)
	{
		s++;
	}
	return i;
}
main()
{
	char arr[]="bangalore";
	int len = pstrlen(arr);
	printf("len is through own fun : %d \n",len);
	printf("len is through strlen : %d \n",strlen(arr));
}
