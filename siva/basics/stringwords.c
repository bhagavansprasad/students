#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	int i,w=0,c=0,n=100;
	char b[100]=" how  are   a     boy    a";
	for(i=0;b[i]!='\0';i++)
	{
		if(b[i]==' ')
		{
				while(i<=n)
				{ 
					if(b[i]==' ')
						i++;
					else 
						break;
				}
				w++;
				i--;

		}
	}
	printf("words are %d\n",w);


}

