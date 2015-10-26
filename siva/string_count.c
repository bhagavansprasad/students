#include<string.h>
#include<stdio.h>
#include<stdlib.h>
main()
{
int i,w=1;
char b[]="aura networks bangalore bomminahalli chennai highway road near lalu bakery";
for(i=0;b[i]!='\0';i++)
{
if(b[i]==' ')
{
w++;
}

}
printf("no of words are %d\n",w);
}
