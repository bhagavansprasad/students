#include <stdio.h>
#include <string.h>
main()
{
	char str1[100] = "Hai";
	char str2[100];
	printf("str1 = %s str2 = %s\n", str1,str2);
	astrcpy(str1,str2);
	printf("str1 = %d str2 = %d\n",sizeof(str1),sizeof(str2));
	printf("str1 = %s str2 = %s\n", str1,str2);
	printf("str1 = %u str2 = %u\n", str1,str2);
	printf("%d\n",sizeof(astrcpy));
}

void astrcpy(char str1[],char str2[])
{

	printf("str1 = %d str2 = %d\n", sizeof(str1),sizeof(str2));
	printf("str1 = %d str2 = %d\n", strlen(str1),strlen(str2));
	printf("str1 = %u str2 = %u\n", str1,str2);
	int i;
	for(i=0;str1[1]!='\0',str2[i]=str1[i];i++);
}
