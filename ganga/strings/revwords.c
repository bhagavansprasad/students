#include <stdio.h>

int main()
{
	char str[20] = "hello world";
	char s[20];
	int i, j = 0;

	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ' '):wq
		{
				s[j] = str[i+1];
				j++;
		}
	}
	printf("%s\n", s);

	for(i = 0; str[i] !=' '; i++)
	{
		s[j] = str[i];
		j++;
	}
	printf("%s\n", s);
}
