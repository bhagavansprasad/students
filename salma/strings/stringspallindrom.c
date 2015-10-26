#include<stdio.h>
int get_pallindrom(char *str );
//int c1=0;
main()
{
	int c1;
	char string[] =  "hello madam peep liril peep sleep";
	c1= get_pallindrom(string);
	printf("no of strings in a strings are : %d \n",c1);
}
int get_pallindrom(char *str )
{
	char *forward;
	char *reverse;
	int c=0;
	forward = str;
	while(*str != '\0' )
	{  
		if( *str == ' ' || *(str+1) == '\0') 
		{ 
				reverse = str-1;
				if( *(str+1) == '\0')
					reverse =str;
				while(reverse != forward)
				{
					while(*forward == *reverse)
					{
						if(reverse <= forward )
						{
							c++;
							break;
						}
						forward++;
						reverse--;
					}
					break;
				}
				forward = str+1;
			}
			if(*(str+1) =='\0')
				break;
			str++;  
		}
	return c;
}
