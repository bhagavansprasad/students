#include<stdio.h>
#include <string.h>
main()
{
	int t;
	char s1[100]="Aura networks in bangalore";
	char s2[100]="Aura books";
	t=astrcmp(s1,s2);
	if(t==0)
	{
		printf("strings are same");
	}
	else if(t==1)
	{
		printf("strings are not same");
	}
}
int astrcmp(char *str1,char *str2)
{
	int i,w;
	for(i=0;str1[i]!='\0';i++)

	{
	if(str1[i]==str2[i])
			w=0;
	}

	
	if(str1[i]!=str2[i])
	{
	w=1;
	}
	
	return w;

}


