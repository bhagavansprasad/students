#include <stdio.h>
/*
main()
  {
      int i=20;
      switch(i)
      {
      case 20: printf("Hello\n ");
              {
      case 1 : printf("World \n");
              }
      case 5: printf("Hello World\n ");
	  }
}
// output----->=Hello
//             =World
//             =Hello World

*/
/*
 main()
{
     char str1[]="Hello";
     char str2[]="Hello";
     if ( str1 == str2 ) 
		 printf("True\n");
	 else
		 printf("False\n");

}
// output--->= False
*/

/*
main()
{
 # include <stdio.h>
 int i = 10 ;
printf("%d\n", i/2 );

}
// output--->=5
*/

/*
#include <stdio.h>   
# pragma pack(2)

struct SIZE
{
	int i;
	char ch ; 
	double db ;
}

main ()
{
	printf ( "%d\n",sizeof(struct SIZE) );
}
//output--->=14
*/
/*
 main()
 {
     int arr[]={ 1,2,3,4 };
     int *ptr ;;;;
     ptr++ = arr;
     printf("%d,%d",ptr[2],arr[2]);
     return 0;
  }
//error= lvalu required as left operand of assignment

*/
/*
main()
{
    char c = 255;
    printf ("%d\n",c); 
	return 0;
}
*/
//output----->= -1

/*
 main()
 {
     int i;
     for (i=7;i<=0;i)
         printf ("hello\n");
 }
//output--->= nathing output
*/

/*
 main()
 {
     printf( printf ("world") );
 }
// output--->= run time error

*/

/*
int  main( )
{
    for( ; ;);
    printf("Hello\n");
}
//output--->= Runs in an infinite loop without printing anything.

*/

/*
int main()
{
    char a[] = "world";
    printf("%d  %d\n",strlen(a),sizeof(a));
    return 0;
}
*/
//output--->= strlen=5,sizeof=6

/*
FUNC (int *p)
{
	p = (int *)malloc(100);
	printf("p valu-->= %x\n",p);
}

int main( )
{
	int *ptr;
	FUNC(ptr);
	printf("Ptr valu--->=:%x\n",ptr);
	return 0;
}
*/
/*
 main()
 {
     char s[10];
     scanf ("%s",s);
	 printf(s);
 }
*/
// output-->= compiler error

/*
main()
{
       int a;
       #define y 10
       a=y;
       printf("%d\n",a);
}
*/
// output-->= 10

/*
void main()
{
     char *mess[]={"Have","a","nice","day","Bye"};
     printf("%d \t %d\n",sizeof(mess),sizeof(mess[1]));
 }
// out put --->= 40,8
*/

/*
void main()
{
	int i,count=0;
	char *p1="abcdefghij";
	char *p2="alcmenfoip";
	for(i=0;i<=strlen(p1);i++)
	{
		if(*p1++ == *p2++)
			count+=5;
		else 
			count-=3;
	}
	printf("count=%d\n",count);
	printf("strings=%s\n",*p1);
}
// output--->= 6
*/

/*
main(int argc,char *argv[])
{
printf((argc > 1 ? "%c" : "%c",*++argv));
}
// input ./a.out crane banglore
// output---= crane
*/

/*
main()
{
	int a;
	char *p;
	a = sizeof(int) * p;
	printf("%d\n",a);
}
// out put-->= compiler error
*/

/*
#define SIZE sizeof(int)
main()
{
	int i=-1;
	if( i < SIZE )
		printf("True\n");
	else
		printf("False\n");
}
// out put --->= False
*/

/*
main()
{
	int a=8,d;
	int *p;
	p=&a;
	d=a/(*p);
	print("%d\n",d);
}
//out put-->= compiler error
*/
/*
main()
{
	char *a="Hello";
	*a++ = 'h';
	printf("%s\n",a);
}
// out put-->= compiler error
*/
/*
main()
{
	char p[]="Hello";
	p[0]='h';
	printf("%s\n", p);
}
*/
// output-->= hello

/*
 #define mysizeof(a) (&(a)+1) - &(a))
main()
{
float d;
//printf("float size-->=%d\n",sizeof(d));
printf("%d\n", mysizeof(d) );
}
// out put-->= compile error
*/

/*
main()
{
	int *p=10;
//	int *a=&p;

	//printf("%d\n",*a);
	printf("%d\n",*p);
}
// output-->= compile error
*/

/*
main()
{
	int i=-1;
	i<<=2;
	printf("%d\n",i);
}
// out put-->= -4
*/
/*
main()
{
	int i= 0xffffffff;
	printf("%d\n",i);
	printf("%d\n",sizeof(i));

}
// out put-->= -1,4
*/

/*
#include<stdio.h>
main()
{
	scanf("%d");
	printf();
}
*/
// out put-->= compiler error

#include<stdio.h>
#define islower(c) ('a'<=(c) && (c)<='z')
#define toupper(c) (islower(c)?(c)-('a'-'A'):(c))
main()
{
	char *p="i am fine";
	while(*p)
		//printf("%c",toupper(*p++));
		printf("%c",islower(*p++));
}

