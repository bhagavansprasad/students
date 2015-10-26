#include<stdio.h>
#include<string.h>
main()
{
char s[]="AURAA NETWORKS IN BANGALORE";
char d[35];
int cpy;
string_ncpy(s);
//printf("%s",d);
}

int string_ncpy(char s[])
{
int i,n=5;
char d[35];

for(i=0;i<5;i++)
{
d[i]=s[i];
}
d[n]='\0';
printf("%s\n",d);
}

