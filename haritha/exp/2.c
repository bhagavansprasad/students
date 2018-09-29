#include <stdio.h>
main()
{
	char ch[100]="aura networks";
	display(ch);
}
int display(char*p)
{
	int i;
	for(i=0;*p!='\0';i++,p++)
	{
		printf("%s",p[i]);
	}
}

