#include <stdio.h>
int main(int argc,char *argv[])
{
	int i=1,j,res = 0,key;
	for(j=0;j<argc;j++)
	{
		printf("-->%s\n", argv[j]);
	}
	key = gen_key(argv[i]);
	switch(key)
		{
			case 1:			printf("entered in case\n");
							res = add(argv[i+1],argv[i+2]); 
							printf("sum-->%d\n",res);
							break;
		}
}


int add(char *a,char *b)
{
	printf("a-->%d\tb-->%d\n",atoi(a),atoi(b));
	return (atoi(a))+(atoi(b));
}


int gen_key(char *str)
{

	printf("entered in gen_key\n");
	printf("%s\n",str);
	if((strcmp(str,"ADD") || strcmp(str,"add"))==0)
	{
	printf("computed return val:\n");
	return 1;
	}
}
