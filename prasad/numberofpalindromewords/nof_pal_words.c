#include"stdio.h"
#include"nofpalwrords.h"
struct data
{
char str[100];
int nop;
};
struct data d[3]={{"   hello  mam     madam ",2},
		{"hah radar malayalam",3},
		{"she madam",1}};
main()
{
int i, w;
for(i=0;i<3;i++)
{
w=get_nof_pal(d[i].str);
printf("w=%d \n",w);
if(w!=d[i].nop)
printf("MYprogram is wrong");
else if(w==d[i].nop)
printf("My program is correct\n");
printf("nop[i]=%d \n",d[i].nop);
}
}
