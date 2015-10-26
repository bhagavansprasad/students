#include <stdio.h>

char* my_strstr(char *s2, char *s1)
{
	int i, j;
	int flag = 0;

	if ((s2 == NULL || s1 == NULL)) return NULL;

	for( i = 0; s2[i] != '\0'; i++)
	{
		if (s2[i] == s1[0])
		{
			for (j = i; ; j++)
			{
				if (s1[j-i] == '\0'){ flag = 1; break;}
				if (s2[j] == s1[j-i]) continue;
				else break;
			}
		}
		if (flag == 1) break;
	}

	if (flag) return (s2+i);
	else return NULL;
}

int main()
{
	char s2[] = "This is the statement";
	char s1[] = "sta";
	char *temp;

	temp = my_strstr(s2,s1);
	printf(" Sub string is :%s\n ",temp);
	return 0;
}
