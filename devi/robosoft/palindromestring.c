#include<stdio.h>
#include <string.h>
//#include<conio.h>
int stpal(char str[50], int st, int ed);
void main()
{
char str[50];
int pal=0,len=0,i,start=0,end;
printf("\n\n\t ENTER A SENTENCE…: ");
gets(str);
while(str[len]!='\0')
len++;
len--;
for(i=0;i<=len;i++)
{
if((str[i]==' ' && str[i+1]!=' ') || i==len)
{
if(i==len)
end = i;
else
end=i-1;
if(stpal(str,start,end))
pal++;
start=end+2;
}
}
printf("\n\n\t THE TOTAL NUMBER OF PALINDROMES ARE..: %d",pal);
}


int stpal(char str[50], int st, int ed)
{
int i, pal=0;
for(i=0; i<=(ed-st)/2; i++)
{
if(str[st+i]==str[ed-i])
pal = 1;
else
{
pal = 0;
break;
}
}
return pal;
}
