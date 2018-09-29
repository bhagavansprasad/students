#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,n,k = 0, w = 0;
	char s[100]={"radar madam hello    level   121   abcba      hi   "};
	printf("string ======= %s\n",s);
	char d[100];
	for(i=0;s[i]!='\0';i++)
	{
		for( ;s[i]==' ';i++);
		for(j=0;s[i]!='\0'&&s[i]!=' ';i++,j++)
		{
			d[j]=s[i];
		}
		d[j]='\0';
		if(d[0] != ' ' && d[0] != '\0')
		{
			w++;
			printf("%s\n",d);
			n=palstr(d);
			if(n==0)
			{
				k++;
			//	printf("---- %s\n",d);
			}
		}
	}
	printf("the no of palindromes ===  %d\n",k);
	printf("the no of words === %d\n",w);
}
int palstr(char *str)
{
	int i,j;
	for(i=0,j=strlen(str)-1;i<=j;i++,j--)
		if(str[i]!=str[j])
			break;
	if(i>j)
		return 0;
	else
		return 1;
}
