#include <stdio.h>
/*main()
{
 int i,j=0;
 char arr[5]={"paidi"};
 char arr1[5];
 for(i=0;arr[i]!='\0';i++)
 {
  arr1[j]=arr[i];

 }
// arr1[j]='\0';
 printf("str_cpy--->= %s\n",arr1);
 printf("str_cpy--->= %s\n",arr);
}

*/

main()
{
 char str1[10]="paidi";
 char str2[10];
 my_fuction(str1,str2);
}

int my_fuction(char *a,char *b)
{
   printf("%c\n",*a);
   while(*a!='\0')
   {
     *b = *a;
	 b++;
	 a++;
   printf("%c\n",*b);
   }
   *b='\0';
   printf("%s\n",b);
}
