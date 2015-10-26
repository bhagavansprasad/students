#include <stdio.h>
main()
{
	int i,wc=0;
	char s[100]="      hi  i   am  raghu ";
	for(i=0;s[i]!='\0';i++)
	{
			if((s[i]!=' ')&&((s[i+1]==' ')||(s[i+1]=='\0')))
			wc++;
	}
	printf("%d",wc);
	printf("\n");
}
