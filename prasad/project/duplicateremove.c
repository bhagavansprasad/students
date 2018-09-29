#include"stdio.h"
int arr[100]={1,2,3,1,2,4,5,1,6,3,7,8},c=12,i,j,k;

int duplicate_removepup()
{
for(i=0; i<c; i++)
{
for(j=i+1; j<c; j++)
{
if(arr[i]==arr[j])
{
for(k=j; k<c; k++)
arr[k]=arr[k+1];
c--;
j--;
}
}
}
}

display()
{
for(i=0; i<c; i++)
printf("\n %d \n ",arr[i]);
}

main()
{
printf("before duplicate removing \n");
display();
duplicate_removepup();
printf("After duplicate removing \n");
display();
}
