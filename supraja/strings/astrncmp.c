astrncmp(char *d,char *s,int n)
{
int w,i;
for(i=0;d[i]==s[i]&&i<=10;i++)
{
if(s[i]=='\0'||d[i]=='\0')
w=0;
}
if(s[i]!=d[i])
w=-1;
return (w);
}
