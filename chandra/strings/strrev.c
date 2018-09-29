#include <stdio.h>
#include <string.h>
main()
{
	char s[20] = "balachandrudu";
	char b[100] = {"     rameshkumar reddy"};
	char c[100];
	astr_rev(s);
	printf("%s\n", s);
}

int astr_rev(char *a)
{
	char *start = a, *end, t;
	for(end = a + (strlen(a) - 1); end > start; end--, start++)
	{
		t = *end;
		*end = *start;
		*start = t;
	}
	return 0;
}

/*int pstrcpy(char *a, char *b)
{
	while(*a++ = *b++);
	*a = '\0';
}
int pstrlen(char *a)
{
	int len = 0;
	while(*a++ != '\0')
	{
		len++;
	}
	return len;
}
int pstrcat(char *a, char *b)
{
	int flag = 0;
	while(1)
	{
		if(*a == '\0')
		{
			flag = 1;
		}
		if(flag == 1)
		{
			*a = *b;
			b++;
			if(*b == '\0')
				break;
		}
		a++;
	}
	return 0;
}
int astr_rev(char *d, char *s)
{
	int l, i;
	for(l = 0; s[l] != '\0'; l++);
	printf("%d", l);
	for(i = 0; s[i] != '\0'; i++)
		d[l-i] = s[i];
	return 0;
}*/
