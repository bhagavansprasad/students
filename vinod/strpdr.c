#include<stdio.h>
#include<string.h> 
main()
{
	char a[]="aumrmua 121 tit 1234 12121 aura level network",s[10];
	int i,j=0,flag;	
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!=' ' || a[i+1]!='\0')
		{
			s[j]=a[i];
			j++;
		}
		if(a[i]==' ' || a[i+1]=='\0')
		{
			if(a[i+1]=='\0')
				s[j]='\0';
			if(a[i]==' ')
				s[j-1]='\0';
			flag=is_palindrome(s);
			if(flag==1)
				printf("%s is palindrome\n",s);
			else
				printf("%s is not palindrome\n",s);
			j=0;
		}
	}
}	
int is_palindrome(char *p)
{
	int i,m,len=0,flag=1;
	len=strlen(p);
	m=len/2;
	for(i=0;i<=m;i++)
	{
		if(p[i]!=p[len-1])
		{
			flag=0;
			break;
		}
		len--;
	}
	/*if(p[i]==p[m])
		flag=1;*/
	return flag;
}
