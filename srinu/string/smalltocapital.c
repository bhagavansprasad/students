#include<stdio.h>
main()
{
	int i;
	char s1[10]="sreenu";
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]>=97 && s1[i]<=122)
			s1[i]=s1[i]-32;
	}
	printf("%s\n",s1);
}
