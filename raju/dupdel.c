#include<stdio.h>
main()
{
	int i,j,t,k=0;
	int a[8]={2,6,4,6,8,4,6,10};
	for(i=0;i<8;i++)
	{
	  for(j=i+1;j<8-k;j++) //if k is not there garbage values will compare
	  {
	    if(a[i]==a[j])
		{
		   k++;   // k helps in removing garbage values
		   t=j;
		   printf("k:%d\t  i:%d\t j:%d\t a[i]:%d\t a[j]:%d\n",k,i,j,a[i],a[j]);
		   for( ;j<7;j++)
		   {
		     a[j]=a[j+1];
		   }
		    a[j]='\0';
			j=t; 
		 }
	   }
	 }  
	 printf("K:%d\n",k);
	   for(i=0;i<8-k;i++)   // if k is not there garbage values will print
	   {
	     printf("%d\n",a[i]);
	    }	 
	 
}	 
