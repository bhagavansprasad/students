#include<stdio.h>

char *amemset(char str[],char target[], int a)
{
	int i;
	for(i=0;i<a;i++)
	{
		str[i]=target[0];
	}
	return str;
}

int main()
{
	char str[]=" On the way";
	char target[]="P";

	char *res;
	res=amemset(str,target,5);
	printf(" %s \n", res );
}
