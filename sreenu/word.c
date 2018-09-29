#include<stdio.h>
char a[100]={"                    how rr u"};
int wordcount(char p[]);
main()
{
	
	int c;
	
		c=wordcount(a);
		printf("%s %d",a,c);
	
}
int wordcount(char p[])
{
	int i,j=0;
	for(i=0;p[i]!='\0';i++)
			if((p[i]!=' '&&p[i+1]==' ')||(p[i]!=' '&&p[i+1]=='\0'))
				j++;


	printf("%d \n",j);	
		return j;
	
}
