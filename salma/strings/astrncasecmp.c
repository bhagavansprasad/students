#include<stdio.h>
#include<string.h>
int astrncasecmp(char arr1[],char arr2[],int a)
{
int i=0;
for(i=0;i<=a && arr1[i] && arr2[i];i++)
{
if(arr1[i]==arr2[i]-32||arr1[i]==arr2[i]+32);
else if(arr1[i]==arr2[i]);
else 
{
return 0;
}
}
return 1;
}
main()
{
char str1[20]="salMa";
char str2[20]="SalMa";
int t;
t=astrncasecmp(str1,str2,3);
if(t==1)
printf("both r equal\n");
else
printf("both r different\n");
}

