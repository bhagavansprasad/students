#include <stdio.h>
void main()
{
    int  num=10101010, decimal_val = 0, base = 1;
  
int binary_val = num;
  
  while (num > 0)
    {
        decimal_val = decimal_val + ((num % 10) * base);
        num = num / 10 ;
        base = base * 2;
    }
    printf("The Binary number is = %d \n", binary_val);
    printf("Its decimal equivalent is = %d \n", decimal_val);

}
