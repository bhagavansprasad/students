#include<stdio.h>
#include<string.h>
main()
{
char s[]="AURA NETWORKS IN BANGALORE";
char d[35];
int cpy;
string_cpy(s);
//printf("%s",d);
}

int string_cpy(char s[])
{
int i;
char d[35];
int n=strlen(s);
for(i=0;s[i]!='\0';i++)
{
d[i]=s[i];
}
d[n]='\0';
printf("%s\n",d);
}

