#include <stdio.h>
#include<string.h>
void reverse(char str[],int start,int end);
void reverse_letters(char str[],int start,int end);
int main(void)
{
	char str[100];
	strcpy(str,"i have many books");
	reverse_letters(str,0,strlen(str)-1);
	puts(str);
	return 0;
}
//void reverse_words(char str[],int start,int end)
//{
//	reverse(str,start,end);
//	reverse_letters(str,start,end);
//}
void reverse_letters(char str[],int start,int end)
{
	int w_start,w_end;
	for(w_start=w_end=start;w_end<end;w_end++)
	{
		if(str[w_end]==' ')
			continue;
		w_start=w_end;
		while(str[w_end]!=' '&&w_end<=end)
			w_end++;
		w_end--;
		reverse(str,w_start,w_end);
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
