#include<stdio.h>
#include<string.h>
/*main()
{
 char name[4][60]={
                   "paidi kumar ",
                    "banglore ",
                    "aura net"
                 };
   
printf("%s\n",name[0]);
printf("%d\n",name[0]);
printf("%s\n",name[1]);
printf("%d\n",name[1]);
printf("%s\n",name[2]);
printf("%d\n",name[2]);*/

/* main()
{
	char *str="bommanahalli";
	int i;
	while(*str!='\0')
	{
                i=-1;
                printf("%c",*str);
                printf("\n");
	       // str++; 
                printf("-->%u= ",str);
                str++;
	}
}*/

/* main()
{
 char str[]="paidikumar";
 char *p;
 p=str;
 int i=0;
 while(*p!='\0')
 { 
 

  printf("%c",*p);
  p++;
 }
  printf("\n");

}*/


main()
{
char*str[]={
             "rajam",
             "nandipadu",
             "aura net"
           };
int i=0;
while(*str[1]!='\0')
  {
    printf("%c\n",*str[1]);
   // printf("%u",&str[1]);
    str[1]++;
  }
  printf("\n");
}
