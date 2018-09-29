#include <stdio.h>
char *astrchr(char *s,char ch)
{
	int i;
	for(i=0;s[i];i++)
	{
		if(s[i]==ch)
			return (&s[i]);
	}
	return NULL;
}
main()
{
	char s[]="bangalore",ch = 'h';
	char *ptr;
	ptr=astrchr(s,ch);
	if(ptr)
	printf("char is at %s \n",ptr);
	else printf("there is no character\n");
}
