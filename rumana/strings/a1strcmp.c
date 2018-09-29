#include<stdio.h>
main()
{
	char str1[]="hello",str2[]="hello";
	int k;
	k=astrcmp(str1,str2);
	if(k==0)
		printf("same and k val is %d\n",k);
	else
		printf("not same k val is %d\n",k);
}


int astrcmp(char str1[],char str2[])
{
	int i,c=0;
	for(i=0;  str1[i]!='\0'&&str2[i]!='\0'  ;i++)
	{
		if(str1[i]!=str2[i])
		{
			c++;
			break;
		}
	}
	return c;
}

