#include"stdio.h"
#define MAX 10
int c=0,i;

int db_insert_element(int *arr,int val,int index)
{
    if(index>=MAX)
    {
	printf("The array boundry exceeds we cannot insert element--->%d \n",val);
	return;
    }
  if(index<=c)
  {
  for(i=MAX; i>=0; i--)
    {
	if(i==index)
	{
	    arr[i+1]=arr[i];
	    arr[i]=val;
	    c++;
	    return;
	}
	arr[i+1]=arr[i];
    }
   }

  arr[index+1]=arr[index];
    arr[index]=val;
    c++;
}

int db_delete_element(int *arr,int index)
{
if(index>=MAX)
{
printf("the index given is outof array boundary ");
return;
}
for(i=index; i<MAX; i++)
arr[i]=arr[i+1];
c--;
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
    db_insert_element(arr,10,0);
    db_insert_element(arr,20,1);
   db_insert_element(arr,30,2);
   db_insert_element(arr,40,3);
    db_insert_element(arr,50,4);
    db_insert_element(arr,60,5);
    db_insert_element(arr,70,6);
    db_insert_element(arr,80,7);
    db_insert_element(arr,90,8);
    db_insert_element(arr,100,9);
printf("before deletion\n");
display(arr);
db_delete_element(arr,3);
printf("after deletion\n");
display(arr);
}
