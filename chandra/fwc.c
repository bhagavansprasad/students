#include<stdio.h>
main()
{
	int i,c=0,f=0;
	char buff[100]=" ";
	for(i=0;buff[i]!='\0';i++)
	{
		if(buff[i]==' ')
		{
			c++;
		}
		if(buff[i]!=' ')
		{
			f=1;
		}
	}
	if(f==0)
	{
		printf("%d",c);
	}
	printf("%d",c);
}
