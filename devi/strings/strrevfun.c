#include <stdio.h>
#include <string.h>
main()
{
	char str[]="He llom";
	printf("%s\n",str);
	int n = strlen(str);
	astrrev(&str,n);
	printf("%s\n",str);
}

void astrrev(char *str,int n)
{
	int i,j;
	char temp;
	for(i=0,j=n-1;i<n/2;i++,j--)
	{	
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
