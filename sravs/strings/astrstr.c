#include<stdio.h>
#include<string.h>
int aststr(char *str1[],char *str2[]);
main()
{
	int ret;
	char buff1[]="aura networks";
	char buff2[]="ura";
	printf("%s \n",buff1);
	printf("%s \n",buff2);
	ret = astrstr(buff1,buff2);
	printf("%d \n",ret);

}

int astrstr(char* str1[],char* str2[])
{
	int i=0,j,t=NULL;
	for(i=0;str1[i]!=str2[0];i++);
 	return i;

	for(j=0;str2[j]!=str1[i];j++);
	return 0;

  
		
}



