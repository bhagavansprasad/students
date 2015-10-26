#include <stdio.h>
/*  main()
{
 char a[]={1,2,3,4};
 printf("%d\n",a[0]);
 printf("%d\n",sizeof(a));
}
*/
/*
main()
{
 char a[2][3]={
                 1,2, 3,4,
				 5,6, 7,8,
			  };
 printf("%u\n",*(a[0]+2));

}*/
/*
main()
{
 char a[3][3][3]={
 				{
                  1,2,3,4,
				  5,6,7,8,
				  9,10,11,12
				  },
				  {
				   13,14,15,16,
				   17,18,19,20,
				   21,22,23,24,
				  }
				  };
				  printf("%u %u %u %d ",a,*a,**a,***a);
}*/
main()
{
 int a[4]={1,2,3,4,5};
 char *p;
 p=(char *)(a);
 printf(" add---> %u\n",p);
 printf("valu---> %d\n",*p);
 printf("valu---> %d\n",*p+0);
 printf("add----> %u\n",p+0);
 printf("valu---> %d\n",*p+1);
 printf("add----> %u\n",p+1);
 printf("valu---> %d\n",*p+2);
 printf("add --->%u\n",p+2);
 printf("valu---> %d\n",*p+3);
 printf("add --->%u\n",p+3);
}
