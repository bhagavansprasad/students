#include <stdio.h>
int main( )
{
  int *p ;
  p = ( int * ) malloc ( 20 ) ;
  printf ( "%d\r\n", p ) ;
  free ( p ) ;
  printf ( "%d\r\n", p );
  return 0;
}


