#include<stdio.h>
main()
{
	int i,j,n,temp;
	int arr[]={10,30,20,50,40,25};
        n=sizeof(arr)/sizeof(int);

        for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
        printf("\n");

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
    }
		for(i=0;i<n;i++)
                printf("%d\n",arr[i]);
	

}
