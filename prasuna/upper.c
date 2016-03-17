#include <stdio.h>
main()
{
	char ch='A';
	int to_lower(char ch);
	int t;
	t=to_lower(ch);
	printf("%c",t);
}
int to_lower(char ch)
{
	if(ch>='A'&&ch<='Z')
	ch=ch+32;
	return ch;
}
