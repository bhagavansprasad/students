#include<stdio.h>
int main()
{
	int a[10]={12,5,1,5,64,15,4,45,85,54};
	int i,pos=3,size=10;
	/*printf("\nEnter size of the array: ");
	  scanf("%d",&size);

	  printf("\nEnter %d elements in to the array: ",size);
	  for(i=0;i<size;i++)
	  scanf("%d",&a[i]);

	  printf("\nEnter position where to delete: ");
	  scanf("%d",&pos);*/

	i=0;
	while(i!=pos-1)
		i++;
	while(i<10)
	{
		a[i]=a[i+1];
		i++;
	}

	size--;
	for(i=0;i<size;i++)
		printf(" %d\n",a[i]);
}
