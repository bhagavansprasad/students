#include "stdio.h"

void main()
{
 int n = 1, age_in_sec = 0;
 age_in_sec = (((n/4) * 366 )+ ((n-(n/4)) * 365)) * 24 * 60 * 60;

 printf("--> your age in seconds is :%d\n", age_in_sec);
 }
