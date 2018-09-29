#include<string.h>
#include<stdio.h>
main()
{
int w=0,i;
char b[]="how r u";
for(i=0;b[i]!='\0';i++)
{
	if(b[i]== ' ')
	{
		for(;b[i]==' ';i++);
	}
	if((b[i]>='A' && b[i]>='Z') || (b[i]>='a' && b[i]>='z'))
	{
		if(b[i]!=' ' )
		{
			//w++;
			for(;b[i]!=' ';i++);
			
		}
w++;
	}
//w++;
}
printf("%d\n",w);
}
