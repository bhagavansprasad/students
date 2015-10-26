#include<stdio.h>
main()
{
	int linecount=0;
	char str[100]="my \n name \n is \n bunitu";
	linecount=get_linecount(str);
	printf("%d",linecount);
}
int get_linecount(char*p)
{
	int i,lc;
	while(1)
	if(p[i]=='\n')
	{
	lc++;


