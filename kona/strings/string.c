#include <stdio.h>
#include <string.h>
void reversestr(char str[]);
main()
{

	char str[50];
	strcpy(str,"sreenu");
	reversestr(str);
	puts(str);
}
	void reversestr(char str[])
	{
		int i,j;
		char tmp;
		for(i=0,j=strlen(str)-1;i<=j;i++,j--)
		{
			tmp=str[i];
			str[i]=str[j];
			str[j]=tmp;
		}
	}

