#include <stdio.h>
main()
{
	char a = 'A';
	char *ptr = &a;

	printf("the val of a is a = %c and addr is &a = %u\n" , a, &a);
	printf("ptr to char is ptr = %u and val at addr is *ptr = %c\n", ptr, *ptr);

	char str[10]="Networks";
	char *ptr1 = &str;

	printf("val of str=%s and addr is &str=%u\n", str, str);
	printf("val of ptr1=%u and val at addr *ptr1=%c\n",ptr1, *ptr1);

	/*char str2[10][100]={
					     " ",
					     "aURA",
						 "nETWOrk"
					   };
	char **ptr2 = str2;

	printf("val of str=%s and addr is &str2 = %u",str2[0], str2);
	printf("val of ptr2 = %u and val at str *ptr2 = %s", ptr2,*ptr2);*/
	
	
	const int b = 10;
	int *iptr = &b;
	printf("const int b = %d and addr is %u\n", b,&b);
	printf("int * iptr = %u and addr is &iptr = %u and val is *iptr = %d",iptr, &iptr, *iptr);
	//b = 30; error: read only var
	//printf("const int b = %d and addr is %u\n", b,&b);
	const int *ptr3 = &b;
	printf("val at b is *ptr3 = %d and addr is &ptr3 = %u val in ptr3 =	%u",*ptr3, &ptr3, ptr3);
	ptr3++;
	printf("ptr3++ = %u\n", ptr3);
}
