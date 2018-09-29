#include<stdio.h>
#define MSG 16
main()
{
char *msg1="hello world";
char *msg2="welcome";
char *msg3="embedded c";
char inbuf[MSG];
int p[2],j;
pipe(p);
write(p[1],msg1,MSG);
write(p[1],msg2,MSG);
write(p[1],msg3,MSG);
for(j=0;j<3;j++)
{
read(p[0],inbuf,MSG);
printf("%s\n",inbuf);
}
}
