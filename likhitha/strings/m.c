#include <stdio.h>
int main()
{
	char s1[100]="aura net";
	char s2[10] = "";
	int n = 20;

	astrncpy(s2, s1, n);
	printf("s1 :%s\n", s1);
	printf("s2 :%s\n", s2);
}
