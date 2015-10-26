int getwordcount(char *str)
{
int j,wc=0;
for(j=0;str[j]!='\0';j++)
{
while(str[j]==' ')
j++;
if(str[j]!=' '&& str[j]!='\0')
wc=wc+1;
while(str[j]!=' ' && str[j]!='\0')
j++;
}
return wc;
}
