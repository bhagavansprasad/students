#include"stdio.h"
int palin(char *s1);
int get_nof_pal(char *src)
{
int i,j,n,c=0;
char dest[10];
for(i=0;src[i]!='\0';i++)
{
while(src[i]==' ')
i++;
for(i,j=0;src[i]!=' '&&src[i]!='\0';j++,i++)
{
dest[j]=src[i];
}
dest[j]='\0';
n=palin(dest);
if(n==1)
c=c+1;
}
return c;
}


