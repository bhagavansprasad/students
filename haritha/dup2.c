#include<stdio.h>
 
 main() {
   int arr[6]={2,1,4,4,1,7}, i, j, k;
   for (i = 0; i < 6; i++) {
      for (j = i+1 ; j < 6;j++) {
         if (arr[j] == arr[i]) {
            for (k = j; k < 6; k++) {
               arr[k] = arr[k + 1];
            }
            
         } 
      }
   }
 
   for (i = 0; i < 6; i++) {
      printf("%d ", arr[i]);
   
   }
   }
   
