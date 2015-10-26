#include<stdio.h>

void right(char *str,int n)
{
	int k,j;
	char str1[50];

	for(k=0;str[k];k++);

	str1[n] = '\0';

	for(j=0;j<n;j++)
		str1[j] = str[k-n+j];

	printf("String of Right most copied is %s\n",str1);
}


int main()
{
	char str[50];
	int n;
	printf("Enter the string : ");
	scanf("%s",str);
	printf("Enter the number of characters to be copied : ");
	scanf("%d",&n);
	right(str,n);
}
