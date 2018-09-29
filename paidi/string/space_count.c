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
        }
          printf("%d \n",w);
}
