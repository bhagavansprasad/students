#include<stdio.h>
#include<string.h>
main()
{
	char str[100]="aabbc  eejfkcggddet";
	char s=firstnonrepeatedcharacter(str);
	printf("%c\n",s);
}
int firstnonrepeatedcharacter(char *str)
{
	int i,j,repeated;
	int len=strlen(str);
	for(i = 0 ; i < len ; i++)
	{
		repeated = 0;
		for(j = 0 ; j < len ; j++)
		{
			if(i != j && str[i] == str[j])
			{
				repeated = 1;
				break;
			}
		}
		if(repeated == 0)
		{
			return str[i];
		}
	}
}
