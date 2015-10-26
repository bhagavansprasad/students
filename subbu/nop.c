#include<stdio.h>
main()
{
	int i,c=1,j,n=10,count=0;
	for(i=2;i<=n;i++)
	{
	  for(j=2;j<i;j++)
	 {
		if(i%j==0)
		{
			count++;
			break;
		}
	 }
	     if(count==0)
    	{
		   c++;
	    	printf("prime number\n");
	    }
            	else
        	{
            	printf("not prime number\n");
	        } 
   }
}	
