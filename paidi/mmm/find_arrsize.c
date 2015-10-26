#include <stdio.h>
#include <string.h>
int main()
{
	char *buff[]={"paidi","chandu","chandana","AURA"};
	printf("string_count-->= %ld\n",sizeof(buff)/sizeof(buff[0]));
	printf("%ld\n",sizeof(buff));
	char arr[]="paidi";
	printf("%d\n",sizeof(arr));
	printf("%d\n",strlen(arr));
}
