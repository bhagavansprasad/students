#include<stdio.h>
#include<fcntl.h>
main()
{
	char s[100];
	int r,l=10,t=0,sum=0;
	int fd=open("a.txt",0,O_RDONLY);
	do
	{
		r=read(fd,s,l);
		s[r]='\0';
		printf("%s\n",s);
		t=palindrome(s);
		printf("                               T value:%d\n",t);
		sum=sum+t;
	}while(r==l); 
	printf("No. of Palindromes:%d\n",sum);
}
int palindrome(char s[])
{
	char p[100];
	int nop=0,i,j=0,k=0;
	for(i=0;s[i]!='\0';i++)
	{
		for(;s[i]==' ';i++);
		j=i;
		for(;s[i]!=' ';i++)
		{
			if((s[i]>=48 && s[i]<=57)||(s[i]>=65 && s[i]<=90) || (s[i]>=97 &&
						s[i]<=122))
			{
			}
			else 
				break;
		}
		k=i-1;
		printf("Before j:%d\t Before k:%d\n",j,k);
		if(j<k)
		{
			printf("if j:%d\t if k:%d\n",j,k);

			while(s[j]==s[k])
			{
				j++;
				k--;
				printf("j:%d\t k:%d\n",j,k);

				if(j>=k)
				{
					nop++;
					break;
				}
			}
		} 
	}
	return nop;
}	



