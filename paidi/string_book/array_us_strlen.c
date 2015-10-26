#include <string.h>
#include <stdio.h>
int my_strlen(char str[]);
main()
{
	char str[20]="paidikumar";
	int i;
	i = my_strlen(str);
	printf("strlen--->=%d\n",i);
}

int my_strlen(char str[])
{
	int i=0;
	while(str[i]!='\0')
		i++;
	return i;
}


/*#include <string.h>
#include <stdio.h>

main()
{
	char str[20]="paidikumar";
	int i=0;
	while(str[i]!='\0')
		i++;
	printf("strlen--->=%d\n",i);
}

*/
