#include<stdio.h>
/*#include<string.h>
int astrcmp(char *s1,char *s2);

main()
{
	char s1[]="Hi Hello How are";
	char s2[]="Hi Hello How are you";
	int t;
	printf("s1:%s s2:%s\n",s1,s2);
    t=astrcmp(s1,s2);
	printf("t:%d\n",t);
	if(t==0)
	{
	  printf("STRINGS ARE EQUAL\n");
	}
	else
	   printf("STRINGS ARE NOT EQUAL\n");


}	*/
int astrcmp(char *s1,char *s2)
{
	int i;

	for(i=0;s1[i]==s2[i];i++)
	{
		if(s1[i]=='\0')
		{
		  return 0;
		}
	}
	
	return 1;
}	



