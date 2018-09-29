#include<stdio.h>
#include<string.h>
main()
{
	char a[]="paidi kumar v";
	int i,c=0,w=0,n=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==' ')
			w=w++;
		for( ;a[i]==' ' ;i++);
		if(a[i]>=65 && a[i]<=122)
		{
			c=c++;	
		}	
		if(a[i]=='\n')
		{
			n++;
		}		

	}
	printf("characters-->%d \n words-->%d \n lines-->%d \n",c,w,n);
}
