#include <stdio.h>
/*main()
{
 char str[]="paidi";
 char str1[]="paidi";
 if(str == str1)
  printf("unequall\n");
  else
  printf("equall\n");
}*/
/*
main()
{
  char p;
 char *ptr[2]={
               "hello",
			   "paidi"
              };
	p = swap(&ptr[0],&ptr[1]);
	printf("%s\n %s\n",*(ptr+0),*(ptr+1));
    return 0;
}
int swap(char *t1,char *t2)
{
 //printf("++++%d\n",*t1);
 char a;
 a = t1;
 //printf("-----%d\n",a);
 t1 = t2;
 //printf("====%d\n",t1);
 t2 = a;
 //printf("****%d\n",t2);
 
}
*/


// return in two pointers of valluse//

/*main()
{
  int c,a=10,b=20;
  c=add(&a,&b);
  printf("%d %d\n",a,b);
}
int add(int **x,int **y)
{
  int n;
  n=*x;
  *x=*y;
  *y=n;

}*/

/*
main()
{
 printf("\n");
 printf(5 + "paidikumar\n");
}*/

/*
main()
{
 printf("paidi" "puji\n");
 return 0;
}*/

/*
main()
{
 char a[25]="paidikumar pujitha";
 printf("--%s\n",&a+3);
 printf("%c\n",*(a+3));
 printf("%c\n",a[3]);
}*/

/*
mai()
{
void fun();
fun();
printf("\n");
return 0;
}
void fun()
{
 char c;
 if((c=getchar())!= '\n')
 fun();
 printf("%c",c);

}*/

main()
{
 char p1[]="paidi";
 char p2[10];
 char *t,*s;
 t=p1;
 s=p2;
 while(*s = *t)
 {
  *t++ = *s++;
  }
  printf("%s\n",p2);
  return 0;

}
