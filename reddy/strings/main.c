#include<stdio.h>

struct mystrings_t
{
	char s1[100];
	char s2[100];
};

struct mystrings_t strings[] = {
	{"Aura Networks", "AuRA NeTWorks"},
	{"Bangalore", "Bangalore"},
	{"Kadapa", "Kdp"},
	{"K", "k"},
	{"k", ""},
	{"K", "K"},
	{"BANGLORE","banglore"},
	{"hai","hellow"},
	{"ha","  "},
	{"aura networks","aura banglore"},
	{"aura networks","aura netwobang"}
};

int main()
{
	char s1[] = " ";
	char s2[] = "An Equalatoral Triangle  ";
	int  i, retval;
	int len = 3;

	for (i = 0; i < 11; i++)
	{
		retval = astrncasecmp(strings[i].s1,  strings[i].s2, 10);

		if (retval == 0)
		{
			printf("-->%d. SAME: %s<-->%s, retval :%d\n", i+1, strings[i].s1, strings[i].s2, retval);
		}
		else
		{
			printf("-->%d. NOT SAME: %s<-->%s, retval :%d\n", i+1, strings[i].s1, strings[i].s2, retval);
		}
	}
	
	return 0;
}
