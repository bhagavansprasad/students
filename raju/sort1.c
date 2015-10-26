#include<stdio.h>
main()
{
	int i,j,n=5,temp;
	int a[5]={55,44,11,33,22};
	for(i=0;i<n-1;i++)
	{
	  for(j=0;j<n;j++)
	  {
	    if(a[j]>a[j+1])
		{
		  temp=a[j];
		  a[j]=a[j+1];
		  a[j+1]=temp;
		}
	  }
	}
    printf("Sorted elements of array\n");
	for(i=0;i<n;i++)
	{
	  printf("%d\n",a[i]);
	}
}	

	  
