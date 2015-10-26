#include <stdio.h>
#include <string.h>
main()
{
	char str[] = "Aura";
	char str1[] = "Networks";
	char *ptr = "bang";
	char *ptr1 = "India";
	char *ptr2 = "NULL";
	//str = ptr; array and pointer str expects string
	//printf("%s", str);
	ptr = str; // pointer and array ptr expects address str gives addr
	printf("%s\n", ptr);
	//str = str1;// array and array str expects string
	//printf("%s", str);
	ptr = ptr1; // pointer and pointer ptr expects addr ptr2 gives addr
	printf("%s\n", ptr);
	ptr2 = str;// pointer and string ptr2 expects addr
	printf("%s\n", ptr2);


	// string copy

	strcpy(ptr2, "aura");
	printf("ptr2 = %s\n", ptr2);
	//strcpy(ptr1, "aura");
	//printf(" ptr1 = %s\n", ptr1);
	strcpy(ptr2, ptr1);
	printf("ptr2 = %s\n", ptr2);
	strcpy(ptr2, str);
	printf(" ptr2 = %s\n", ptr2);
	//strcpy(ptr1, str);
	//printf(" ptr1 =%s\n", ptr1);
	strcpy(str, ptr1);
	printf("str = %s\n", str);
	//strcpy(ptr, ptr1);
	//printf( "ptr = %s\n", ptr);
	strcpy(str, str1);
	printf("str = %s\n", str);
	strcpy(str, str1);
	printf("str = %s\n", str);


	// string concatenation

	ptr2 = strcat(str, str1);
	printf(" ptr2 / str = %s\n", str);
	//ptr2 = strcat(ptr, ptr1);
	//printf("ptr2 = %s\n", ptr2);
	ptr2 = strcat(str, ptr1);
	printf("ptr2 = %s\n", ptr2);
	ptr2 = strcat(ptr, str);
	printf("ptr2 = %s\n", ptr2);
}
