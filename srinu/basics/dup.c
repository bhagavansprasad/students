#include<stdio.h>
main()
{
	int i,j,n=6;
	int a[6]={2,6,4,6,8,6};
	for(i=0;i<n;i++)
	{
	  for(j=i+1;j<n;j++)
	  {
	    if(a[i]==a[j])
		{
		  a[j]=0;
		}
	  }
	}
	printf("Elements after replacing Duplicates\n");
	for(i=0;i<n;i++)
	{
	  printf("%d\t",   a[i]);
	}
}	
