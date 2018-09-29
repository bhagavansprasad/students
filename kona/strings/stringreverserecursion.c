#include <stdio.h>
#include <string.h>
main()
{
	char str[10]="sreenu";
	reverse(str,0,strlen(str)-1);
	printf("the string after reversing is :%s\n",str);
}
void reverse(char str[],int index,int size)
{
	char temp;
	temp=str[index];
	str[index]=str[size-index];
	str[size-index]=temp;
	if(index==size/2)
	{
		return;
	}
	reverse(str,index+1,size);
}
