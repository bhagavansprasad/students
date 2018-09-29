#include<stdio.h>
#include<string.h>
char* astrcpy2(char *str1,char *str2);
char* astrcpy1(char str1[],char str2[]);
main()
{
  char str1[100]="hi hello how are you";
  char str2[100];
  
  printf("first string %s\n",str1);
  printf("second string is %s\n",str2);
  
  astrcpy1(str1,str2);

  printf("string one is %s\n",str1);
  printf("string two is %s\n",str2);
  astrcpy2(str1,str2);

  printf("string one is %s\n",str1);

  printf("string two is %s\n",str2);

}

char* astrcpy1(char str1[],char str2[])
{
int i;
char* a;
printf("char is %d\n",sizeof(a));

printf("arrays str1 is %d\n",sizeof(str1));
printf("arrays str2 is %d\n",sizeof(str2));

for(i=0;str1[i]!='\0';i++)
{
  str2[i]=str1[i];
}
str2[i]='\0';
return str2;

}

char* astrcpy2(char *str1,char *str2)
{
printf("pointers str1 is %d\n",sizeof(str1));
printf("pointers str2 is %d\n",sizeof(str2));

while((*str2=*str1)!='\0')
{
str2++;
str1++;
}
return str2;

}
