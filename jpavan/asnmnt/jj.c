#include <stdio.h>

int i; /* Global variable, declared outside any function. */

void funct(void);

main()
{
    i = 0; /* i isn't declared in main(), but can still be changed */
    i++; /* Again, changing i by incrementing it */
    printf("The value of i is %d\n", i);
    funct();
    /* i will be different after funct() */
    printf("The value of i is %d\n", i);
}

void funct(void)
{
    i++; /* i isn't declared in funct() either. */
    i += 3;
}
