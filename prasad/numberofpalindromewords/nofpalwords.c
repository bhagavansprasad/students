#include"stdio.h"
int get_nof_pal(char *src);
struct data
{
char str[100];
int nop;
};
struct data d={"   hello  mam     madem ",2};
main()
{
if(get_nof_pal(d.str)!=d.nop)
printf("MYprogram is wrong");
else if(get_nof_pal(d.str)==d.nop)
printf("My program is correct");
printf("nop=%d \n",d.nop);
}
