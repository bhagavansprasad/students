#include<stdio.h>
#include <string.h>

int str_to_lower( char *p);
main()
{
	int retval = 0;
	char str[100]="HEllo HoW aRe yOu";

	printf("Before converting to lower, string is '%s'\n", str);
	retval = str_to_lower(str);
	printf("After  converting to lower, string is '%s'\n", str);
	printf("retval :%d\n", retval);

	wc = get_word_count(str);

	return 0;
}

int str_to_lower(char *p)
{
	int i = 0;
	int cap_count = 0;

	for(i = 0; p[i] != '\0'; i++)
	{
		if (p[i]>=65 && p[i]<=90)
		{
			p[i]=p[i]+32;
			cap_count++;
		}
	}
	return (cap_count);
}

int get_word_count(char *p)
{
	int i = 0;
	int cap_count = 0;

	for(i = 0; p[i] != '\0'; i++)
	{
		if (p[i]>=65 && p[i]<=90)
		{
			p[i]=p[i]+32;
			cap_count++;
		}
	}
	return (cap_count);
}

int str_to_upper(char *p)
{
	int i = 0;
	int cap_count = 0;

	for(i = 0; p[i] != '\0'; i++)
	{
		if (p[i]>=65 && p[i]<=90)
		{
			p[i]=p[i]-32;
			cap_count++;
		}
	}
	return (cap_count);
}

int str_toggle_case(char *p)
{
	int i = 0;
	int cap_count = 0;

	for(i = 0; p[i] != '\0'; i++)
	{
		if (p[i]>=65 && p[i]<=90)
		{
			p[i]=p[i]+32;
			cap_count++;
		}
	}
	return (cap_count);
}
