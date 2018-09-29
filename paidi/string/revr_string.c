#include<stdio.h>
#include<string.h>
int my_fun(char *);
main()
{
	int p;
	char str1[20]="paidikumar";
	my_fun(str1);
	
}

int my_fun(char *str1)
{
	int i=0,n,j=0;
	char str2[20];
	n=strlen(str1);
	printf("lenth-->=%d\n",n);

	for(i=n-1;i>=0;i--)/*for(i=1+i;i<n-1;i++)*/
	{
		str2[j]=str1[i];
		j++;      
	}
	str2[j]='\0';

	printf("input string-->=%s\n :",str1);
	printf("output string-->= %s\n:", str2);
			
}


/*
#include<stdio.h>
#include<string.h>
main()
{
	char str[20]="paidi kumar";
	char revstr[50];
	int i=0,j=0;

     printf("string lenth-->=%d\n",strlen(str));

	for(i=strlen(str)-1;i>=0;i--)
	{
		revstr[j]=str[i];
		j++;
	}

	revstr[j]='\0';
	printf("Input String : %s",str);
	printf("\nOutput String : %s ",revstr);

}


*/


