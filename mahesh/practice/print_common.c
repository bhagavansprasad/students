#include <stdio.h>
main()
{
	char a[10]="mahesh";
	char b[10]="aeiou";
	int i,j,c=0;
	for(i=0;a[i]!='\0';i++)
	{
		for(j=0;b[j]!='\0';j++)
		{
		if(a[i]==b[j])
			c+=1;
		}
	}
	printf("%d\n",c);
}
