#include <stdio.h>
main()
{
	int i,count=0;

	char s[100]="        STRINGS pointers functions  arrays    datatypes   identifiers";

	if(s[0]==' ')
		count=0;
	else
		count=1;

	for(i=1 ; s[i]!='\0' ; i++)	
	{
		if(s[i]==' ' && s[i+1]!=' ' && s[i+1]!='\0')
			count++;
	}	

	printf("%d\n",count);

}

