/*print the given integer in BIG ENDIAN format
  i.e .,a=0x12345678
  as in b=0x78563412
 */
#include <stdio.h>
main()
{
	int a= 0x12345678,b,i;
	for(i= 0; i < 4; i++)
	{
		*(((char*)&b)+i)=*(((char*)&a)+(3-i));
	}
	printf("b:%x",b);
}

