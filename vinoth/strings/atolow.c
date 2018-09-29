#include <stdio.h>
main ()
{
	char s1[100] = "         VINotH   1234   @ .!!!!COM";
	char s2[100];
	int n = 15;
	atolower(s2, s1, n);
	printf ("%s\n", s1);
	printf ("%s\n", s2);
}

int atolower(char *s2, char *s1, int n)
{
	int i = 0;
	for(i=0; s1[i]!='\0' && i < n; i++)
	{
		if(s1[i] >= 65 && s1[i] <= 90)
		{
			s2[i] = s1[i] + 32;
		}
		else
		{
			s2[i] = s1[i]; 
		}
	}
	s2[i]='\0';

}
