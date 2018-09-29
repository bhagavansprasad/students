#include <stdio.h>
#include <string.h>
int length(char *str);
void display(char *str);
void rdisplay(char *str);
main()
{
	char str[50]="sreenu";
	printf("--->the val is :%d\n",length(str));
	display(str);
	printf("\n");
	//rdisplay(str);
}
int length(char *str)
{
	if(*str=='\0')
	return 0;
	return(1+length(str+1));
}
void display(char *str)
{
	if(*str=='\0')
	return;
	putchar(*str);
	display(str+1);
}
#if 0
void rdisplay(char *str)
{
	if(*str=='\0')
	return;
	rdisplay(str+1);
	putchar(*str);
}
#endif

