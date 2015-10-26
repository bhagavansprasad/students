#include<stdio.h>
main()
{
unsigned int num = 0x85020000;

	num = (((num >> 24) | (num << 24)) | (((num << 16) >> 24) << 16)) |(((num << 8) >> 24) << 8);


//int retval = ((((pre>>24)|(pre<<24)))|((((pre<<16)>>24)<<16)|(((pre>>16)<<24)>>16)));
printf("%d\n",num);
}
