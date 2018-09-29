#include<stdio.h>
 
 main() {
   int a[6]={2,4,4,6,6,2};
   int i,j,k;
//   for(l=0;arr[l]!='\0';l++)
   {
   for (i = 0; i < 6; i++) {
<<<<<<< dup2.c
      for (j = i + 1; j < 6;j++) {
         if (a[j] == a[i]) {
=======
      for (j = i+1 ; j < 6;j++) {
         if (arr[j] == arr[i]) {
>>>>>>> 1.2
            for (k = j; k < 6; k++) {
               a[k] = a[k + 1];
            }
            
         } 
      }
   }
 }
   for (i= 0; i<=6 ; i++) {
      printf("%d ", a[i]);
   
   }
   }
   
