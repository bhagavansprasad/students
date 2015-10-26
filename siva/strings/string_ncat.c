#include<stdio.h>
#include<string.h>
main()
{
char s1[40]="aura networks";
char s2[10]="BANGALORE";
int n=strlen(s1);
int j,i;
//for(i=0;s1[i]!='\0';i++);
for(j=0;j<=4;j++)
{
s1[n+j]=s2[j];
}
printf("%s\n",s1);
printf("%s\n",s2);

}
