#include<stdio.h>
#include<string.h>
main()
{
char arr[]="hello world";
int i,j,n=11;
//for(j=0,n=0;arr[j]!='\0';j++,n++);

for(i=0,j=n-1;i<j;i++,j--)
{
arr[i]=arr[i]^arr[j];
arr[j]=arr[i]^arr[j];
arr[i]=arr[i]^arr[j];
}

printf("string is %s\n",arr);
printf("string length is %d\n",sizeof(arr));
}
