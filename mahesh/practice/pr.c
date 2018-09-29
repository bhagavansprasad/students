#include <stdio.h>
main()
{
	char s[]="abc";
	int i;
	for(i = 0;s[i];i++)
	{
		if(s[i]=='c')
		{
			s[i]='d';
			break;
		}
	}
	printf("%s\n",s);
}
