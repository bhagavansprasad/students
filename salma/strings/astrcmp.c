#include<stdio.h>
int astrcmp(char str1[],char str2[]);
main()
{
char str1[]="salma";
char str2[]="mateen";
int t=astrcmp(str1,str2);
if(t==0)
printf("equal\n");
else if(t>0)
printf("string1 is higher\n");
else
printf("string2 is higher\n");
}
int astrcmp(char str1[],char str2[])
{
int i;
 for(i=0;str1[i]==str2[i];i++)
    {
   			if(str1[i]!='\0')
	 		    return 0;
 
	}
  return str1[i]-str2[i];
}
