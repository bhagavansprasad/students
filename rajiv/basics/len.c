#include <stdio.h>
#include <string.h>
main()
{
	int len=0,count=0;
	char str[]="     Dis    is    singiri    rajeev        IAS";

	printf("string is:%s\n",str);
	len=astrlen(str);
    printf("%d\n",len);
	count=getwordcount(str);
	printf("%d\n",count);
} 

int astrlen(char *str)
{
	int i=0;

	while(str[i]!='\0')
	{
		i++;	
	} 
	return i;
} 

int getwordcount(char *str)
{
	int j=0,k=0;
	while(str[j]!='\0')
	{
		if((str[j+1]!=' ')&&(str[j]==' '))
		{
			k++;
		}  
		j++;
	}
	return k;
}
