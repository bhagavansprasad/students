#include <stdio.h>
main()
{
	int num=0x15;

if(!(num & 7)) 
{
	printf("number is divisable by 8 is %d\n",num);     // num divisible by 8
}

/*or

if(! (num << 29) ) { // assuming num is 32 bits
    // num divisible by 8
}
*/
	
}
