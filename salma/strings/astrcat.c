#include<stdio.h>
char *astrcat(char str1[],char str2[]);
main()
{
	char str1[20]="Salma";
	char str2[20]="Mateen";
	astrcat(str1,str2);
	printf("concatenated string :%s\n",str1);
}
char *astrcat(char str1[],char str2[])
{
	int i=0,j=0;
	while(str1[i]!='\0')
		i++;
	while(str1[i++]=str2[j++])
		;
	return str1;

}
