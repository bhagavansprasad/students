#include<stdio.h>
int main() {
   int arr[5]={1,3,1,3,4};
   int i, j, k, size=5;
   for (i = 0; i < size; i++) 
   {
      for (j = i + 1; j < size;) 
	  {
         if (arr[j] == arr[i]) 
		 {
            for (k = j; k < size; k++) 
			{
               arr[k] = arr[k + 1];
            }
            size--;
         } 
		 else
            j++;
      }
   }
   for (i = 0; i < size; i++)
   {
      printf("%d ", arr[i]);
   }
   return (0);
} 
