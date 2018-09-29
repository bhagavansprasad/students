#include<stdio.h>
main()
{
	char a[]="aU123rA",b[]="au123rA";
	int c,n=3;
	c=a_strncmp(a,b,5);
	if(c==0)
		printf("strings are same\n");
	else
		printf("strings are not same\n");
}
int a_toupper(char ch)
{
	if(ch>='a' && ch<='z')
		return ch-=('a'-'A');
	else
		return ch;
}
int a_strncmp(const char *a,const char *b,int c)
{
	int i,j=0;
	for(i=0;i<c;i++)
	{
		if(a_toupper(a[i])!=a_toupper(b[i]))
		{
			j++;
			break;
		}
	}
	return j;
}


