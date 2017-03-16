#include <stdio.h>
main()
{
int x=0,x1=0,x2=0,y=0,y1=0,z=0,z1=0,n=7;
char s1[50]= "aura netwok";
char s2[50]= "AURA netwok bangalore";
char d[50];

x=astrlen(s1);		 																	//1
printf("the given str length %d\n\n",x);

astrcpy(d,s1);																		//2
printf("destination : %s :%s\n\n",d,s1);

y=astrncpy(d,s1,n); 																	//3
printf("upto to nth string destination : %s :%s :%d\n\n",d,s1,n);

y1=astrcmp(s1,s2);																			//4
if(y1==1)
printf("same :%s :%s\n\n",s1,s2);
else
printf("not same :%s :%s\n\n",s1,s2);

z=astrncmp(s1,s2,n);																	//5
if(z==1)
printf("same :%s :%s :%d\n\n",s1,s2,n);
else
printf("not same :%s :%s :%d\n\n",s1,s2,n);

astrcat(s1,s2);																			//6
printf("\nThe concatenate string is :%s\nSource string is :%s\n\n",s1,s2);

z1=astrncat(s1,s2,n);																	//7
printf("\nThe concatenate string is :%s\nSource string is :%s :%d\n\n",s1,s2,n);

x1=astrcasecmp(s1,s2);																	//8
if(x1==1)
printf("same :%s :%s\n\n",s1,s2);
else
printf("not same :%s :%s\n\n",s1,s2);

x2=astrncasecmp(s1,s2,n);																	//9
if(x2==1)
printf("same :%s :%s\n\n",s1,s2);
else
printf("not same :%s :%s\n\n",s1,s2);

atolower(s1);																		//10
printf("given string changed lower:%s",s1);

atoupper(s1);																		//11
printf("given string changed upper :%s",s1);
}
