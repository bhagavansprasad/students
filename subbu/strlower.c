#include<stdio.h>
#include<string.h>
main()
{
int i;
	char str[]=("hi");
	printf("%s\n",str);
		for(i=0;str[i]='\0';i++)
		{
			if(str[i]>='a'&&str[i]<='z')
				str[i]=str[i]-32;
			else
			{
			  if(str[i]>='A'&&str[i]<='z')
			   str[i]=str[i]+32;
			}   

		}
		printf("%s\n",str);
}						
