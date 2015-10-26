#include"stdio.h"
int rstrlen(char *s1);
int palin(char *s1)
{
int i,j,m;
char s2[10];
m=rstrlen(s1);
for(i=0;i<m;i++)
{
s2[m-1-i]=s1[i];
}
for(j=0;j<m;j++)
{
if(s1[i]==s2[i]);
else return 0;
}
return 1;
}

