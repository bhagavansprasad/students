#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int i,j,add,sub,mul,div,mod;

	for(i=0;i<argc;i++)
	{
    	printf("arguments is %s\n",argv[i]);
	}

	if(strcmp(argv[1],"add")==0)
	{
		add=atoi(argv[2])+atoi(argv[3]);
		printf("add is %d\n",add);
	}

	else if(strcmp(argv[1],"sub")==0)
	{
    	sub=atoi(argv[2])-atoi(argv[3]);
		printf("substract is %d\n",sub);
	}

	else if(strcmp(argv[1],"mul")==0)
	{
    	mul=atoi(argv[2])*atoi(argv[3]);
		printf("muliplication is %d\n",mul);
	}
	else if(strcmp(argv[1],"div")==0)
	{
    	div=atoi(argv[2])/atoi(argv[3]);
		printf("division is %d\n",div);
	}

	else if(strcmp(argv[1],"mod")==0)
	{
     	mod=atoi(argv[2])%atoi(argv[3]);
		printf("mod div is %d\n",mod);
	}
	else
	printf("wrong option");
}
