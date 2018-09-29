#include<stdio.h>
int main()
{
char a[]="supraja";
char b[10];
int i=0,j;
for(i=0,j=sizeof(b);a[i]!='\0';i++,j--)
{
b[j]=a[i];
}
b[j]='\0';
for(j=0;j<=sizeof(b);j++)
{
printf("%c\n",b[j]);
}
}

