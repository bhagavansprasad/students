#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s is sunday\n", argv[1]);
	printf("%s %s %s %s %s %s\n", argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]); 
}

/*
   int main( int argc, char *argv[] )  
   {
   printf("Program name %s\n", argv[0]);
   if( argc == 2 )
   {
   printf("The argument supplied is %s\n", argv[1]);
   }
   else if( argc > 2 ) 
   {
   printf("Too many arguments supplied.\n");
   }
   else 
   {
   printf("One argument expected.\n");
   }
   }
 */
