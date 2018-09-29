#include <stdio.h>
#include <string.h>
int getword(char *str,char *str1);
int astrlen(char *str)
{
	int j=0;
	while(str[j]!='\0')
	{
		j++;
	} 
	return j;
}

main()
{
	int count=0;
	char str[]="dad madam punished me ";
	char str1[100];
	printf("string is %s\n",str);
	count=getword(str,str1);
	printf("no. of palindromes in the string are %d\n",count);
}

int getword(char *str,char *str1)
{
	int i=0,k=0,c=0;
	int h=astrlen(str)-1;
	while(str[i]!='\0')
	{
		if((str[i]!=' ')&&(str[i+1]==' '))
		{ 
			str1[c]=str[i];
			c++;
		} 
		while(h>1)
		{
			if(str1[c++]==str1[h--])
			{
				k++;
			}
		}
		i++;
	} 
	return k;
} 

