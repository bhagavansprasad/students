#include <stdio.h>
#include <string.h>
void reversestr(char str[]);
void reverse_letter(char str[],int start,int end);
main()
{
	char str[50];
	strcpy(str,"i have many books");
	reverse_letter(str,0,strlen(str)-1);
	puts(str);
	//reverse(str,start,end);
}
void reverse_letter(char str[],int start,int end)
{
	int i,j;
	for(i=j=start;j<end;j++)
	{
		if(str[j]==' ')
		continue;
		i=j;
		while(str[j]!=' ' && j<=end)
		j++;
		j--;
		reverse(str,i,j);
	}
}
void reverse(char str[],int start,int end)
{
	char tmp;
	while(start<=end)
	{
		tmp=str[start];
		str[start]=str[end];
		str[end]=tmp;
		start++;
		end--;
	}
}
