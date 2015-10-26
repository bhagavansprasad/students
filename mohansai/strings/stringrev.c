#include "stdio.h"

void reverse(char *p)
{

	char *q=p;
	int len =strlen(p)/2;
	
	while(*++q!='\0');
	q--;
	

	while(len--)
	{
		*p=*p + *q;
		*q=*p - *q;
		*p=*p - *q;
		
		p++;
		q--;
	
	}

}

main()
{
	char arr[10]="mohansai";
	reverse(arr);
	printf("arr--> %s\n\r",arr);
}




