#include<stdio.h>
main()
{
	char arr[]="hello madam liril peep madam liril ";
		int c;
	c = get_count(arr);
	printf("the palindrom in string is :%d \n",c);
}
int get_count(char *str)
{
	int i,j,c=0;
	char arr[50];
	for(i=0;str[i]!='\0';i++)
	{
		while(str[i]==' ')
			i++;
		if(str[i]!=' ' && str[i]!='\0')
		{        
			j=0;
			while(str[i]!=' ' && str[i]!='\0')
			{
				arr[j]=str[i];
				i++;j++;
			}
			arr[j]='\0';
			printf(" string for finding palindrom %s \n",arr);
			c= c+get_pallindrom(arr);
		}
	}
	return c;
}
int get_pallindrom(char *arr)
{
	char *p;
	p=arr;
	while(*p!='\0')
		p++;
	p--;
	while(*arr==*p)
	{
		if(arr >= p)
			return 1;
		p--; 
		arr++;
	}
	return 0;
}
