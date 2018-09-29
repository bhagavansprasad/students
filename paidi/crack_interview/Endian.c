#include <stdio.h>
int main()
{
 int a = 0x12345678;
 unsigned char * ptr = (unsigned char*)&a;
 if(*ptr==0x12 ? printf("littel  :\n") : printf("Big Endian   :\n"));
}
