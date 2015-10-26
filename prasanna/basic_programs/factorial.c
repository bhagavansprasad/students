// Factorial

/* Calculate factorial using while loop */
#include<stdio.h>
int main()
{
	int a,f,i;
	printf("Enter a number: ");
	scanf("%d",&a);
	f=1;
	i=1;
	while(i<=a)
	{
		f = f * i;
		i++;
	}
	printf("Factorial: %d\n",f);
	return 0;
}
/*
   --------------------------------------------------------------
 */
/* Calculate factorial using for loop 
#include<stdio.h>
int main()
{
int a,f,i;
printf("Enter a number: ");
scanf("%d",&a);
f=1;
for(i=1;i<=a;i++)
f = f * i;
printf("Factorial: %d",f);
return 0;
}

 */

