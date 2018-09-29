#include <stdio.h>
# pragma pack(1)

struct SIZE 
{
	int i;
	char ch ;
	double db ;
};

main () 
{
	printf ( "%d",sizeof(struct SIZE) );
}

/*main()
  {
  char *s = "Hello";
  printf("%c",1[s]);
  } */
/*
#define islower(c) ( 'a' <=(c) && (c)<= 'z' )
#define toupper(c) (islower(c)?(c)-( 'a' - 'A' ):(c))

main()
{
char *p="i am fine";
while(*p)
{
printf("*p =%c\n",*p);
printf("*p++ =%c\n",toupper(*p++));
}
} */

