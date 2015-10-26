#include<stdio.h>
int main()
{
char dstr[5][15]={
                     "aura networks",
					 "bangalore",
					 "india"
				};
printf("%u\n",dstr)	;
printf("%u\n",dstr[1])	;
printf("%u\n",&dstr)	;
printf("%c\n",dstr[1][1])	;
printf("%u\n",&dstr[1][1])	;
printf("%u\n",dstr+1)	;
printf("%u\n",&dstr+1)	;
printf("%u\n",*&dstr)	;
printf("%u\n",**&dstr)	;
printf("%c\n",***&dstr)	;
}
