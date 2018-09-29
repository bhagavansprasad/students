#include<stdio.h>
main()
{
char *msg="hello world";
int p[2],len=20;
char buff[20];
pipe(p);
write(p[1],msg,len);
//write(p[1],msg,len);
read(p[0],buff,len);
//read(p[0],buff,len);
printf("%s",buff);

}
