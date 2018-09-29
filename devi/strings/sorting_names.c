#include<stdio.h>
#include <string.h>
main()
{
int i,j,n=5;
char
name[10][10]={"program","basics","scope","analysis","chapter"},tname[10][10],temp[10];
for(i=0;i<n;i++)
strcpy(tname[i],name[i]);
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(strcmp(name[i],name[j])>0)
{
strcpy(temp,name[i]);
strcpy(name[i],name[j]);
strcpy(name[j],temp);
}
}
}
for(i=0;i<n;i++)
printf("%s\n",name[i]);
}
