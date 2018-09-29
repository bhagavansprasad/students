#include<stdio.h>

int astrlen(char *str)
{
	int i=0;
	while(*str++ !='\0')
		i++;
	return i;
}

char *astrncpy(char *dest, const char *src, int n)
{
	int  i;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	//for ( ; i < n; i++)
	dest[i] = '\0';

	return dest;
}
int astrncompare(char *str1,char *str2,int value)
{
	int i;
	for(i=0;i<value;i++)
	{
		if(*(str1+i) != *(str2+i))
			return (*(str1+i) - *(str2+i));
	}
	return 0;
}
/*
char *astrrev ( char *s)
{
	int temp;
	int i , j;
	//for (i = 0 ; s[i]!= '\0' ; i++);
	//while(s[i] !='\0')
	//	i++;        

	j = astrlen(s);
	for(i = 0,j-1; i<j; i++,j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	return s;
}
*/
char *a_strchar(char *str,char ch)
{
	int i;
	for(i=0;str[i] !='\0';i++)
	{
		if(str[i] == ch)
			return str+i;
	}
	return 0;
}


main()
{
	char dest[10];
	printf("copied string :%s\n",astrncpy(dest,"pr",3));

	printf("strncompare :%d\n",astrncompare("pras", "prassa", 5));
	printf(astrrev("prasan"));

	printf("char :%s\n",a_strchar("prasanna",'s'));

}



