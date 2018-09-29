#include <stdio.h>
#include <string.h>
//void fun(char *p);

main()
{
	char s[20]="aura";
	int c=65;
	//fun(s);
//}
//void fun(char *p)
//{
	char a;
	a=strchr(s,c);
	printf("%d\n",a);
	//printf("%c\n",a);
}
