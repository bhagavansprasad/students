#include <stdio.h>
#include <string.h>
//struct student
union student
{
	//char k;
    int a;
	//short int k;
	//char a;
	//short int a;
    //char m;
	int m;
	//char l;
};
main()
{
	    //struct student s;
		union student s;
		printf(" %d\n",sizeof(s));
      //printf("%p %d\n",&s.k   ,  sizeof(s.k));
		printf("%p %d\n",&s.a    ,   sizeof(s.a));
		printf("%p %d\n",&s.m  , sizeof(s.m));
	  //printf("%p %d\n",&s.l  , sizeof(s.l));
}
