#include"stdio.h"
#define MAX 10
int count=0,i;

int db_insert_element(int *arr,int val,int index)
{
    if(index<MAX)
    {
	count++;
	arr[index]=val;
	return;
    }
    else
	printf("%d array index given is outof boundry\n",index);
}

main()
{
    int arr[MAX];
    db_insert_element(arr,10,0);
    db_insert_element(arr,20,1);
    db_insert_element(arr,40,3);
    db_insert_element(arr,60,5);
    db_insert_element(arr,80,7);
    db_insert_element(arr,30,2);
    db_insert_element(arr,50,4);
    db_insert_element(arr,70,6);
    db_insert_element(arr,90,8);
    db_insert_element(arr,100,9);
    db_insert_element(arr,110,10);
    for(i=0; i<MAX; i++)
	printf("%d \n",arr[i]);
}

