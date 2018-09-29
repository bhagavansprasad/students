/* #include<stdio.h>
   #include<string.h>
 int my_strcmp(char*,char*);
main()
{
	char first[]="kpaidi";
	char second[]="paidi";
	int x;

	x=my_strcmp(first,second);
	printf("%d\n",x);

	if(x==0)	
		printf("string compar  equall\n");
	else	  
		printf("string compare is not  eqall\n");
	return 0;

}

	int my_strcmp(char *a1,char *a2)
	{
		int i,j;
		for(i=0; a1[i]==a2[i]; i++)
		return (a1[i]-a2[i]);
		   
				
	}*/




#include<stdio.h>
#include<string.h>
main()
{
    char s1[]="paidikumar";
    char s2[]="kpaidikumar";
    int diff;
    diff=string_cmp(s1,s2);
    if(diff==0)
    {
        printf("strings r equal\n");
    }
    if(diff>0)
    {
        printf("string s1>s2\n");
         }
        else
    {
        printf("string s<s2\n");
    }
}
    int string_cmp(char s1[],char s2[])
    {
                    int i;
        for(i=0;s1[i]!='\0' && s2[i]!='\0';i++)
        {   
           // if(s1[i]!=s2[i])
           // {
       
           // }
        }
        return s1[i]-s2[i];
    }
