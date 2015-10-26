#include"stdio.h"
#include"utils.h"
main()
{
char t[25];
char s[]="RAMU";
char *scpy;
//char *rstrcpy();
scpy=rstrcpy(t,s);
printf("THE STRCPY=%s",scpy);
}
