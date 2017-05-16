#include<stdio.h>
main()
{
	int n=4;
	char s1[100]= "aura";
	char s2[100]= " net";
	astrcat(s2,s1);
	printf("%s",s1); 
	printf("\n");

}




int astrcat(char *dest, char *src)
{
	int i,j;
	for(i=0 ; src[i]!='\0' ;i++);
	for(j=0 ; dest[j]!='\0' ;j++,i++)
	{
		src[i]=dest[j];
	}
	src[i]='\0';
	return i;
}




