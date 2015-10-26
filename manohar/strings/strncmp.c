#include <stdio.h>
int str_n_cmp(char *,char *,int );
main()
{
	int n=4;
	char *str="MANOhar";
	char ptr[10]="MANOHAR";
	str_n_cmp(str,ptr,n);
}
int str_n_cmp(char *str,char *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
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

