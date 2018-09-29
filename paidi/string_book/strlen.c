/* #include<stdio.h>
#include <string.h>
int main()
{
	char array[]="paidikumar"; 
	char *pointer;
	int length = 0;

//	printf("size of string-->= %d\n",sizeof (array));
//	printf("lenth of string-->= %d\n",strlen(array));
	pointer = array;

	while(*(pointer+length))
		length++;
	printf("string lenth = %d\n",length);


}

*/


    #include<stdio.h>
    void copy_string(char*, char*);
    main()
    {
    char source[100], target[100];
    printf("Enter source string\n");
    gets(source);
    copy_string(target, source);
    printf("Target string is \"%s\"\n", target);
    return 0;
    }
    void copy_string(char *target, char *source)
    {
    while(*source)
    {
    *target = *source;
    source++;
    target++;
    }
    *target = '\0';
    printf("Target string is///////// \"%s\"\n", target);
    }


