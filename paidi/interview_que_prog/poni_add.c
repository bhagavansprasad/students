#include<stdio.h>
/*main()
{
int i;
for(i=0;i!=6; )
{
if(i==3 ||i==5)
printf("%d\n",i);
i++;
}
}*/

 
/*main()
{
 int a[10]={10,20,30,40};
 printf("%d\n",*a);
 }
*/

char buff[100];
main()
{
 printf("%d\n",*buff+99);
 printf("%d\n",sizeof(buff));
 char *p=sizeof(buff);
 printf("valu--> %d\n",p);
 printf("add--> %u\n",&p);

}
