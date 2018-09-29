#include<stdio.h>
int main()
{

    int a[10]={7,9,10,11,24};
	int i,n=5,search_num=11,c=0,d,mid,l=0,u=n-1;
    while(l<=u)
	{
         mid=(l+u)/2;
         if(search_num == a[mid])
		 {
             c=1;
             break;
         }
         else if(search_num < a[mid])
		 {
             u=mid-1;
         }
         else
             l=mid+1;
    }
    if(c==0)
         printf("The number is not found.\n");
    else
         printf("The number is found.\n");

    return 0;
}

