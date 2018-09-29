#include <stdio.h>
main()
{
  int a=5,b=10;
  a = b+a;
  b = a-b;
  a = a-b;

  printf("%d\n",a);
}

/*
//process two
    a=5;b=10;
    a=a+b-(b=a);
    printf("\na= %d  b=  %d",a,b);

    //process three
    a=5;b=10;
    a=a^b;
    b=a^b;
    a=b^a;
    printf("\na= %d  b=  %d",a,b);

    //process four
    a=5;b=10;
    a=b-~a-1;
    b=a+~b+1;
    a=a+~b+1;
    printf("\na= %d  b=  %d",a,b);

    //process five
    a=5,b=10;
    a=b+a,b=a-b,a=a-b;
    printf("\na= %d  b=  %d",a,b);

  */  
