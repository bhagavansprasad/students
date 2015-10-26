#include"stdio.h"
#define MAX 10
int i,j,c=0;
int ordered_insert(int *arr,int val)
{
    if(c>=MAX)
    {
	printf("the array boundary exceeds \n");
	return;
    }
    for(i=0; i<c; i++)
    {
	if(arr[i]>val)
	{
	    for(j=c; j>=i;  j--)
	    {
		if(j==i)
		{
		    arr[j]=val;
		    c++;
		    return;
		}
		arr[j]=arr[j-1];
	    }
	}
    }
    arr[c]=val;
    c++;
}

display(int *arr)
{
    printf("c==%d \n",c);
    for(i=0; i<c; i++)
	printf("%d \n",arr[i]);
}


main()
{
    int arr[MAX];

    ordered_insert(arr,1);
    ordered_insert(arr,4);
    ordered_insert(arr,2);
    ordered_insert(arr,3);
    ordered_insert(arr,8);
    ordered_insert(arr,5);
    display(arr);
}

