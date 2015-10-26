#include"stdio.h"
#define MAX 10
int c=10,i;

int db_delete_element(int *arr,int index)
{
if(index>=MAX)
{
printf("the index given is outof array boundary ");
return;
}
for(i=index; i<MAX; i++)
{
arr[i]=arr[i+1];
c--;
}
}

display(int *arr)
{
printf("c==%d \n",c);
for(i=0; i<MAX; i++)
	printf("%d \n",arr[i]);
}


main()
{

    int arr[MAX]={1,2,3,4,5,6,7,8,9,10};
    printf("Before deletion \n");
    display(arr);
    db_delete_element(arr,2);
    printf("after deletion \n");
    display(arr);
}
