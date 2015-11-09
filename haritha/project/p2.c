#include<stdio.h>
int a,i;
main()
{
	char s1[20]="hi madam";
	char s2[20];
	char s3[20];
	//int t;
	astrncpy(s2,s1,2);
//		astrncpy1(s3,s1,5);
}
int astrncpy(char*s2,char*s1,int n)
{
int a,i,j;
	for(i=0;s1[i]!='\0'&&i<=1;i++)
	{
	s2[i]=s1[i];
//		if(s1[i]==s1[j])
		{
		printf("%s",s2);

		}
//		j++;
	}
}
/*int  astrncpy1(char*s3,char*s1,int n)
{
	int k,l,m;
	for(k=0;s1[k]!='\0'&&k<5;k++)
	{
	s3[k]=s1[k];
//		if(s1[k]==s1[m])
		{
			printf("%s\n%s\n",s1,s3);
		}
//		m++;
	}
}*/

