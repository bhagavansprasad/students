#include <stdio.h>
int str_cmp(char *,char *);
main()
{
	char *str="MANOHAR";
	char ptr[10]="MANOHAR";
	str_cmp(str,ptr);
}
int str_cmp(char *str,char *ptr)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i] != ptr[i])
		{
			printf("both are not equal\n");
			break;
		}
		else
		{
		printf("both are equal\n");
		}
	}
}
