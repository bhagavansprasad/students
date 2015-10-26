#include <stdio.h>
#include <string.h>
void display(char *);
main()
{
	char a[100]="Aura net";
	display(a);
}
void display(char *p)
{
	int i;
	for(i=0;*p!='\0';i++,p++)
	{
		printf("%c\n",p[i]);
	}
}
