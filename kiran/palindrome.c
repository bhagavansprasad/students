#include <stdio.h>
#include <string.h>
int main()
{
	int n = 0 , i = 0;
	/*char s[10][200] = {
		{" "},{"MOM"},{"   ABCBA HELLO"},{" 1234321 MOM ABCBA"}
	};*/
	char s[200] = {"ABCBA"};
		n = get_palindrome(s);
		printf("%d\n",n);
	
}
int get_palindrome(char *s)
{
	int i = 0, j = 0, c = 0, count = 0, d = 0;
	for( i = 0; i <= strlen(s); i++)
	{
		for( ; s[i] == ' ' ;i++);
		if(s[i]!=' ' && s[i] != '\0')
		{
			for(j = i; s[j] != ' ' && s[j] !='\0'; j++);
			for(c = i, d = j -1; c <= j; c++, j--)
			{
				if(s[c] != s[j])
				break;
			}
			if(c>=j)
			{
				count++;

			}
		}
	}
	return count;
}
