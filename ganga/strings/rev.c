#include<stdio.h>
#include<string.h>
 
int main() {
   char str[100] = "Ramesh";
   char temp;
   int i, j = 0;
 
   i = 0;
   j = strlen(str) - 1;
 
   while (i < j) 
   {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
   printf("Reverse string is :%s\n", str);
   return (0);
}
