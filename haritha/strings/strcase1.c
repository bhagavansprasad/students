#include <stdio.h>

int main ()
{
    char  a[10] = "haariTha";
    char  b[10] = "Haaritha";

    /* Compare using strcmp. */

       if (strcasecmp (a, b) == 0) {
        printf ("the same");
    }
    else {
        printf ("different");
    }
  //  printf (" according to 'strcasecmp'.\n");
    return 0;
}
