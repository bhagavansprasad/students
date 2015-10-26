#include<stdio.h>
#include<signal.h>
 void abc();
 main()
 {
  printf("press <del>key\n");
  signal(SIGINT,abc);
  signal(SIGINT,abc);
  signal(SIGINT,abc);
  for( ; ; );
  }
  void abc()
  { 
   printf("you have passed  the <del> key.\n");
   }
