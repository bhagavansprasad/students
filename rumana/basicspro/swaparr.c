#include<stdio.h>
#include<string.h>
main()
{
	char array1[10]={4,5,6,7};
	char array2[10]={1,2,3,4};

int	index =0,i,j,n=4;
while(array1[index]!='\0' || array2[index] != '\0')
{
    array1[index] = array1[index] ^ array2[index];

    array2[index] = array1[index] ^ array2[index];
   // printf("arr2 elements is %d\n",array2[index]);
    array1[index] = array1[index] ^ array2[index]; 
   // printf("arr1 elements is %d\n",array1[index]);
    index++;
}

for(i=0;i<n;i++)
printf("array1 elements are%d\n",array1[i]);
for(j=0;j<n;j++)
printf("array2 elements are %d\n",array2[j]);

}
