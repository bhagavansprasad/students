#include<stdio.h>

/*int main(){

    int num,i,count=0;
    printf("Enter a number: ");
    scanf("%d",&num);

    for(i=2;i<=num/2;i++)
	{
        if(num%i==0)
		{
         count++;
            break;
        }
    }
   if(count==0 && num!= 1)
        printf("%d is a prime number",num);
   else
      printf("%d is not a prime number",num);
   return 0;
}*/

#include<stdio.h>
int main()
{
	int num,i,count;
	for(num = 1;num<=100;num++)
	{
		count = 0;
		for(i=2;i<=num/2;i++)
		{
			if(num%i==0)
			{
				count++;
				break;
			}
		}
		if(count==0 && num!= 1)
			printf("%4d ",num);
	}
	printf("\n");
	return 0;
}
