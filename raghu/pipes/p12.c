#include <stdio.h>
int get_val(char ch)
{
	if(ch>=97&&ch<=122)
		return('z'-ch);
	else if(ch>=65&&ch<=90)
		return('Z'-ch);
}
main()
{
	int i,rval=0;
	char ch='A';
	char arr[26];
	for(i=0;i<26;i++)
	{
		arr[i]=i+65;
	}
	//for(i=0;i<26;i++)
	//	printf("-->arr[%d]:%c\n",i,arr[i]);
	rval=get_val(ch);
	printf("-->%c\n",arr[rval]);
}
