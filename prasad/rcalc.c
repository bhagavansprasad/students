#include"stdio.h"
#include"rfuns.h"
main(int argc,char *argv[])
{
int m,n,l;
float l1;
char str[]="add";
char str1[]="mul";
char str2[]="sub";
char str3[]="div";
m=ratoi(argv[2]);
n=ratoi(argv[3]);
if(a=((rstrcmp(argv[1],str))==0))
{
l=m+n;
printf("addition=%d",l);
return;
}
else if((rstrcmp(argv[1],str1))==0)
{
l=m*n;
printf("multiplication=%d",l);
return;
}
else if((rstrcmp(argv[1],str2))==0)
{
l=m-n;
printf("sub=%d",l);
return;
}
else if((rstrcmp(argv[1],str3))==0)
{
l1=(float)m/n;
printf("div=%f",l1);
return;
}
else 
printf("the function doesn't exist");
return;
}
