#include<stdio.h>
#include<string.h>

char strs[10][100]={ 
	"madam is a mom",
	"12321 123456 abcdef eeeeee",
	" ",
	"madam mam",
	"aura networks"
};

int string_polindrome(char *str)
{
	int i,len;
	len=strlen(str);
	for(i=0;i<len/2;i++)
	{
		if(*(str+i)!=*(str+len-i-1))
			return 0;
	}
	return 1;
}

main()
{
	int i,j,k,l,count=0,m;
	char p[10]=" ",string[100];

	for (i = 0; i < 5; i++)
		printf("-->%d. %s\n", i+1, strs[i]);

	return 0;

#if 0
	for(l=0;l<=4;l++)
	{
		for(m=0;strs[l][m]!='\0';m++)
		{
			string[m]=str[l][m];
		}
		printf("%s",string);
		for(i=0;string[i]='\0';i++)
		{
			for(j=i,k=0;string[j]!=' ';j++,k++)
			{
				p[k]=string[j];
				if(string[j]=='\0')
					break;
			}
			i=j;
			if(string_polindrome(p))
			{
				count=count+1;
			}   
		}
		printf("Number of palindromes in a given string:%d\n",count);
	}
#endif
}  
