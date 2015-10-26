#include <stdio.h>
#include<string.h>
char *astrrchr(char *s, int p); 
main()
{
	char s[100]="eswar kumar p ravi zshake ravi";
	char *x;
	x=astrrchr( s, 'z');
	if(x!=NULL)
	printf("%s\n",x);
	return 0;
}
char *astrrchr(char *s, int p)
{
	int i= 0,j=0;
	for(j=0;s[j]!='\0';j++);
	for(i = j-1;i!=0;i--)
		if(s[i] == p)
		{
			return &s[i];
		}
	return NULL;
} 
