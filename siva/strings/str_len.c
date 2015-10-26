#include<stdio.h>
#include<string.h>


main()
{
	char b[]="siva krishna";
	int length;
	length=str_len(b);
	printf("%d\n",length);
}
int str_len(char b[])
{
	int count=0,i;
	for(i=0;b[i]!='\0';i++)
	{
		count++;
	}
	return count;
}

