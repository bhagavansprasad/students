#include <stdio.h>
void main()
{
 char arr[] = "INTERVIEW";
 printf("arr[5]        :%c\n",arr[5]);
 printf("[arr]5        :%c\n",5[arr]);
 printf("*(arr+5)      :%c\n",*(arr+5));
 printf("*(5+arr)      :%c\n",*(5+arr));
 }
