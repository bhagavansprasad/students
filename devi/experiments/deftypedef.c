#include <stdio.h>
typedef char * ptr;
#define PTR char *
int main()
{
ptr a,b,c;
PTR x,y,z;
printf( "sizeof a:%u\n" ,sizeof(a) );
printf( "sizeof b:%u\n" ,sizeof(b) );
printf( "sizeof c:%u\n" ,sizeof(c) );
printf( "sizeof x:%u\n" ,sizeof(x) );
printf( "sizeof y:%u\n" ,sizeof(y) );
printf( "sizeof z:%u\n" ,sizeof(z) );
return 0;
}


/*A typedef is just a new name for an already existing type and defines are handled by the preprocessor while typedefs are handled by the C compiler itself.
#define can be used to rename anything not just a type like typedef.................for e.g.

#define AND && and we cant use typedef for that like typedef && AND; its not possible with typedef...... some more examples like #define PRINT printf("hello") or #define sum(a,b) (a+b)....all this is not possible with typedef...................

we all know this very well so i am not going to explain this but what will
happen if we use #define to rename a type................*/
