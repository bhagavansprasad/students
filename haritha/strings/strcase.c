#include <stdio.h>
int i,t;
main()
{
	char s1[10]="haritha";
	char s2[10]="Haaritha";
	t=astrcasecmp(s1,s2);
	if(t==0)
	{
		printf("both are same");
	}
	else
		printf("both are different");
}
int astrcasecmp(char*s1,char*s)
{

//int strcicmp(char const *a, char const *b)
//{
 //   for (;; s1++, s++) {
   //     int d = tolower(*s1) - tolower(*s);
     //   if (d != 0 || !*s1)
       //     return d;
   // }
//}
for(i=0;s1[i]!='\0';i++)
	{
	if(s1[i]=='A'&& s1[i]=='Z')
			s[i]=s1[i]+32;	
	
	if(s[i]='a'&& s[i]=='z');

	 
			return 0;
	}
	return 1;
}
	
