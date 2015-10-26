#include<stdio.h>
int main()
{
char str[15]="aura networks";
printf("%u\n",str);
printf("%u\n",&str);
printf("%u\n",str+1);
printf("%u\n",&str+1);
printf("%u\n",*&str);
printf("%c\n",*str);
printf("%c\n",**&str);
}
