/*
#include <stdio.h>
#define NIBBLE(n) (( n & 0x0F )<<4 | (n & 0x0F)>>4)
main()
{
int p;

p=NIBBLE(100);
printf("%u\n",p);
}
*/

unsigned char swapNibbles(unsigned char x)
{
    return ( (x & 0x0F)<<4 | (x & 0xF0)>>4 );
}
 
int main()
{
    unsigned char x = 43;
    printf("%x", swapNibbles(x));
}
