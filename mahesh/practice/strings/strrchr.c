#include <stdio.h>
int astrrchr(char s[],char ch)
{
	int j= strlen(s)-1;
	for(j;j>=0;j--)
	{
		if(s[j]==ch)
			return &s[j];
	}
	return NULL;
}
main()
{
	char arr[]="bangalore";
	char ch = 'a';
	char *ptr;
	ptr = astrrchr(arr,ch);
	if(ptr)
	printf("char is found at %s\n",ptr);
	else printf("there is no char in string \n");
}
