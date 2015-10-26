#include<stdio.h>
int is_palindrome(char *);
int main()
{
	char a[]="        aumrmua 1252          tit 1234 12121 aurrua         level network 5423    ",s[10];
	int i,j=0,flag;	
	for(i=0 ; a[i]!='\0' ; i++)
	{
		if(a[i]!=' ' && a[i]!='\0')
		{
			s[j]=a[i];
			for( ; a[i+1]!=' ' && a[i+1]!='\0' ; i++)
			{
				s[j+1]=a[i+1];
				j++;
			}
			s[j+1]='\0';
			printf("%s\n",s);
			flag=is_palindrome(s);
			if(flag==1)
				printf("%s is palindrome\n",s);
			else
				printf("%s is not palindrome\n",s);
		}
		j=0;
	}
	return 0;
}
