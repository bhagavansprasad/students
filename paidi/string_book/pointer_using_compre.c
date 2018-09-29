#include<stdio.h>
char my_function(char *,char *);
main()
{
  char *str1 = "paidi";
  char *str2 = "kumar";
  int compare;
  compare =my_function(str1,str2);
  if(compare == 0)
   printf("string Equal\n");
   else
   printf("string not Equal\n");
}

char my_function(char *fist,char *second)
{
  int i;
  for(i=0;*fist !='\0' && *second != '\0';i++)
  {
     if(*fist != *second)
	 {
	   *fist++;
	   *second++;
	   return 1;
	 }
	 return 0;
  }
}
