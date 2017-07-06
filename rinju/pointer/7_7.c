#include<stdio.h>
main()
{
char dstr[5][15]={ "Aura networks","banglore","india"};	
printf("%u  ",dstr);
printf("%u  ",dstr[1]);
printf("%u  ",&dstr);
printf("%c  ",dstr[1][1]);
printf("%u  ",&dstr[1][1]);
printf("%u  ",dstr+1);
printf("%u  ",&dstr+1);
printf("%u  ",*&dstr);
printf("%u  ",**&dstr);
printf("%c  ",***&dstr);

}
