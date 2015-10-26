#include<stdio.h>
main()
{
	char a[10]="Aur12 nET",*p=a;
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i]>='A' && a[i]<='Z')
			printf("%c is capital\n",p[i]);
		else if(a[i]>='a' && a[i]<='z')
			printf("%c is not capital\n",p[i]);
		else
			printf("%c is not a alphabet\n",p[i]);
		i++;	
	}
}
