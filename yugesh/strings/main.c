#include <stdio.h>
#include "defs.h"
main()
{
char s1[20]="bangalore aura";
char s2[20]="welcome aura";
char s3[20];
int n=5,b;

astrncpy(s3, s1, n);

printf("astrncpy:%s\n",s3);
astrcpy(s3, s1);
printf("astrcpy:%s\n",s3);

astrcat(s2,s1);
printf("s1=%s\n s2=%s\n",s1,s2);
int a=astrlen(s2);
printf("%d\n",a);
astrncat(s2,s1,n);
printf("s1=%s\n s2=%s\n",s1,s2);
a=astrcmp(s1,s2);
if(a==0)
printf("same");
else
printf("not same"); 
b=astrncmp(s1,s2,n);
if(b==0)
printf("same");
else
printf("not same");
} 
