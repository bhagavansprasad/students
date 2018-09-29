#include<stdio.h>
main()
{
	int t;
	char name[ ] ="aura banglore";

	t=astrlen(name);
	printf( "\n length of string : %d\n",t);
	//puts("\n length of string: %d\n",t);

}
int astrlen(char *ptr)
{
	int i;

	for(i=0;ptr[i]!='\0';i++)
		printf("%c",ptr[i]);

	return (i);
}

