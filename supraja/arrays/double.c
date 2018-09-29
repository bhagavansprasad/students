#include <stdio.h>
main()
{
char dstr[5][15]={
                      "Aura Networks",
					  "Bangalore",
					  "India"
					  };
printf("%u\n",dstr);
printf("%u\n",dstr[1]);
printf("%u\n",&dstr);
printf("%u\n",dstr[1][1]);
printf("%u\n",&dstr[1][1]);
printf("%u\n",dstr+1);
printf("%u\n",&dstr+1);
printf("%u\n",*&dstr);
printf("%u\n",**&dstr);
printf("%c\n",***&dstr);
}
