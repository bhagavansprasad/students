#include <stdio.h>
#include <string.h>
main()
{
	char str1[] = "Aura";						
	char str2[] = "Networks";
	char str5[] = "India";
	char *str3 = "marthahalli";
	char *str4 = "bangalore";
	char *str6;
	/*/ string copy

	strcpy(str5, str1);//array and array
	printf("%s\n", str5);
	//strcpy(str6, str2);// ptr and array
	//printf("%s\n", str6);
	//strcpy(str3, str4);//pointer and pointer
	//printf("%s\n", str3);
	strcpy(str1, str4);//array and pointer
	printf("%s\n", str1); */

	// string concatenation

	strcat(str2, str1);//array and array
	printf("%s\n", str2);
	strcat(str1, str3);//array and pointer
	printf("%s\n", str1);
	//strcat(str3, str4);// pointer and pointer
	//printf("%s\n", str3);
	strcat(str4, str6);// pointer and array
	printf("%s\n", str4);

}
