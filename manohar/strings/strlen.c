#include <stdio.h>
int a_strlen(char *);
main()
{
	char *a="hi my name is manohar iam in bangalore";
	a_strlen(a);
}
int a_strlen(char *a)
{
	int i,len=0;
	for(i=0;a[i]!='\0';i++)
	{
		len++;
	}
	printf("%d\n",len);
}

