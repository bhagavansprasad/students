#include<stdio.h>
main()
{
	int i,j,n=5,temp;
	int a[5]={55,44,11,33,22};
	for(i=0;i<n;i++)
	{
	  for(j=i+1;j<n;j++)
	  {
	    if(a[i]>a[j])
		{
		  temp=a[i];
		  a[i]=a[j];
		  a[j]=temp;
		}
	  }
	}
    printf("Sorted elements of array\n");
	for(i=0;i<n;i++)
	{
	  printf(" %d\t",a[i]);
	}
}	
