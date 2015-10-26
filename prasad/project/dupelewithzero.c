#include"stdio.h"
int arr[100]={1,2,3,4,1,3,4,6,1,9},j,i;
int duplicate_replace()
{
    for(i=0; i<10; i++)
    {
	for(j=i+1; j<10; j++)
	{
	    if(arr[i]==arr[j])
		arr[j]=0;
	}
    }
}
display()
{
    for(i=0; i<10; i++)
	printf("%d \n",arr[i]);
}


main()
{
    duplicate_replace();
    display();
}
