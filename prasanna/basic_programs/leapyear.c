/* Check Leap Year */
#include<stdio.h>
int main()
{
    int y;
    printf("Enter a year: ");
    scanf("%d",&y);
    if(y%4 == 0 )//|| y%400 == 0)
	printf("Leap Year\n");
//    else if(y%100 == 0)
 //       printf("Not a Leap Year\n");
    else 
	printf("Not a leap year\n");
   return 0;
}
