/* Insertion Sort */
/*
#include<stdio.h>

int main()
{
int a[10],i,j,new;
printf("Please enter 10 values:\n");
for(i=0;i<5;i++)
scanf("%d",&a[i]);

for(i=1;i<5;i++)
{
new=a[i];
for(j=i-1;j>=0&&new<a[j];j--)
{
a[j+1]=a[j];
}
a[j+1]=new;
}

printf("Sorted Array is:\n");
for(i=0;i<5;i++)
printf("%d\n",a[i]);

return 0;
}
 */
/*Sorting Elements of an array in ascending order using insertion sort algorithm*/ 
#include<stdio.h> 
int main() 
{
	int data[100],n,temp,i,j;
	printf("Enter number of terms(should be less than 100): "); 
	scanf("%d",&n); 
	printf("Enter elements:\n "); 
	
	for(i=0;i<n;i++) 
	{
		scanf("%d",&data[i]);
	} 
	for(i=1;i<n;i++) 
	{ 
		temp = data[i]; 
	//	j=i-1; 
	//	while(temp<data[j] && j>=0) 
			/*To sort elements in descending order, change temp<data[j] to temp>data[j] in above line.*/ 
	for(j=i-1;j>=0 && temp>data[j];j--)
	{ 
		data[j+1] = data[j];
// --j;

	}
		data[j+1]=temp; 
	} 
	printf("In ascending order:\n ");
	for(i=0; i<n; i++) 
		printf("%d\n",data[i]); 
	return 0; 
}

