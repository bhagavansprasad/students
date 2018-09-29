#include<stdio.h>
main()
{
char str1[]="siva krishna";
char size=(sizeof(str1));
printf("Size of String is --->%d\n",size);
char str2[13];
xstrcpy(str1,str2);
}
xstrcpy(char *s1,char *s2)
{
//printf("%s\n",s1);
while(*s1!='\0')
{
*s2=*s1;
s2++;
s1++;
}
*s2='\0';

printf("%s",s2);
}

