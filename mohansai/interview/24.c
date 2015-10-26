#include <stdio.h>
#include <stdlib.h>

void main() 
{
    int apple,orange; 
    int ctr = 0; 
    int Fruits[2][3]; 
    for (apple =0; apple <3; apple ++)
    for (orange =0; orange <2; orange ++) 
    { 
          Fruits [apple][ orange] = ctr; 
          ++ctr; 
    }
    printf("%d", ctr);
}

