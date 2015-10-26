#include<stdio.h>
int compare_string(char*, char*);

main()
{
	char first[100]="paidi";
	char second[100]="paidi";
	char result;

	result = my_comparefunction(first, second);

	if ( result == 0 )
		printf("Both strings are same.\n");
	else
		printf("Entered strings are not equal.\n");
	return 0;
}


int my_comparefunction(char *first, char *second)
{
	while(*first==*second)
	{
		if ( *first == '\0' || *second == '\0' )
			break;
		first++;
		second++;
	}
	if( *first == '\0' && *second == '\0' )
		return 0;
	else
		return -1;
}
