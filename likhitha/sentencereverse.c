
#include <stdio.h>

int main()
{
	char s[100]="i am happy";
	char rev[100]=" ";
	asenrev(s,rev);
	printf("%s\n",s);
	printf("%s\n",rev);
}

int asenrev(char *s,char *rev)
{
	int i,j,k=0;
	for(i=0;s[i]!='\0';i++);
	{
		if(s[i+1]==' ' || s[i+1]=='\0')
		{
			for(j=i;j>=0 && s[j]!=' ';j++)
			{
				rev[k]=s[i];
				k++;
				i--;
			}
		}
	}
	rev[k]='\
