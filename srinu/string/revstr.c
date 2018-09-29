#include <stdio.h>
#include<string.h>
void reverse(char str[],int start,int end);
void reverse_letters(char str[],int start,int end);
int main(void)
{
	char str[100]={"i have many books"};
	//strcpy(str,"i have many books");
	reverse_letters(str,0,strlen(str)-1);
	printf("%s\n",str);
	return 0;
}
void reverse_letters(char str[],int start,int end)
{
	int i,j;
	for(i=j=start;j<end;j++)
	{
		if(str[j]==' ')
			continue;
		i=j;
		while(str[j]!=' '&&j<=end)
			j++;
		j--;
		reverse(str,i,j);
	}
}
void reverse(char str[],int start,int end)
{
	char temp;
	while(start<=end)
	{
		temp=str[start];
		str[start]=str[end];
		str[end]=temp;
		start++;
		end--;
	}
}
