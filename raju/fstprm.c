#include<stdio.h>
int isPrime(int i);

main()
{
	int n,c=0,p=0,sum=0,i;
	printf("enter a number");
	scanf(" %d",&n);
	for(i=1;c<n;i++) // n represents number of prime no.s,n=4 1st 4 prime no.s
	{
//<<<<<<< fstprm.c
		p=isPrime(i);

		if(p==0)
		{
			c++;
			sum=sum+i;
			printf(" %d",i);
		}

//=======
	  p=isPrime(i);
	  printf("p:%d\t i:%d\n",p,i);
	  if(p==1)
	  {
	    c++;
		sum=sum+i;
		printf("prime: %d\n",i);
	  }
	  
//>>>>>>> 1.3
	} 
//<<<<<<< fstprm.c
	printf(" %d",sum);
//=======
/*	 i=1;
	   do
	   {
	     p=isPrime(i);
		 if(p==1)
		 {
		   c++;
		   sum=sum+i;
		   printf(" %d",i);
		  }
		  i++;
		 }while(c<n);    */ 
/*	   for(i=1;i<=n;i++)  // upto number n, print prime no.s.doesn't need c
	   {
	     p=isPrime(i);
		 if(p==1)
		 {
		    sum=sum+i;
			printf(" %d",i);
		  }
		}                 */
	   printf("Sum: %d\n",sum);
//>>>>>>> 1.3
}

//NP - 1
//P  - 0
int isPrime(int n)
{
	int k;

	for(k = 2; k <= n; k++)
	{
		if(n%k == 0)
		{
			return 1;
		}
	}

	if(k==n)
	{
		return 0;
	}
}   
