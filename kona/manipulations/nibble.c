#include<stdio.h>
#include<stdlib.h>
 unsigned char swap(unsigned char c)
{
unsigned char t1, t2;
t1 = c & 0x0F;   //For extracting the last 4 bits ( From MSB )
t2 = c & 0xF0;   //For extracting the first 4 fits ( From MSB )
t1=t1 << 4;      //Shifting the bits to left by 4 places
t2=t2 >> 4;      //Shifting the bits to right by 4 places
return(t2|t1);   //concatinate the bits
}

int main(void)
{
char c=0x1234; //Test subject of this program
printf("\nTest Value is %x\n", c);
printf("\nThe Swapped value is %x\n",swap(c));
//system("pause");
return 0;
} 


