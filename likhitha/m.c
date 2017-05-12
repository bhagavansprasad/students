#include <stdio.h>
int main()
{
	char n1[100]="aura net";
	char n2[6];
	int i=6;
	astrncpy(n2,n1,i);
	printf("%s\n",n1);
	printf("%s\n",n2);
}
