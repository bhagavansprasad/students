#include<stdio.h>
#include<string.h>
main()
{
	char *str[5]={"white","red","green","yellow","blue"};

	int i,j;

	char *t;

	printf("before sorting:\n");

	for(i=0;i<5;i++)

		printf("%s\n",str[i]);

	for(i=0;i<5;i++)

		for(j=i+1;j<5;j++)

			if(strcmp(str[i],str[j])>0)
			{
				t=str[i];

				str[i]=str[j];

				str[j]=t;
			}
	printf("after sorting:\n");

	for(i=0;i<5;i++)

		printf("%s\n",str[i]);

	printf("\n");
}
