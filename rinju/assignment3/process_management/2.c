 #include <stdio.h>
 main()
   { 
	printf( " I am forking a child process \n ");
	fork ();
	fork ();
	fork ();
	printf( "who am i ? child or parent ? My ID process : %u \n ", getpid());
   }

