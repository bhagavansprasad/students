#include<stdio.h>
main()
{
int a=10,b=20;
func1(a,b);
}
int func1(int c,int d)
{
printf("----a:%u\n,---b:%u\n",&c,&d);
int e=30;
long f=50;
func2(e,f);

}
int func2(int g,long h)
{
printf("----a:%u\n,---b:%u\n",&g,&h);
int i=30;
long f=50;
func3(i,f);


}
int func3(int l,long d)
{
printf("----a:%u\n,---b:%u\n",&l,&d);

}

