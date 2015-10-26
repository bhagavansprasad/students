#include<stdio.h>
main()
{
	char s[100]="hello  my name is umesh      rajaravivarma world";
	int i,w=0;
	for(i=0;s[i]!='\0';i++)
	{
		for(   ;s[i]==' '&& s[i]!='\0';i++);
		for(   ;s[i]!=' '&& s[i]!='\0';i++);
		w++;
	}
	printf("%d",w);
}


