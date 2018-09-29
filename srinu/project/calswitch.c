#include<stdio.h>
main(int argc,char *argv[])
{
	int a, b,j, result=0;
	char str_cmd[128];
	strcpy(str_cmd, argv[1]);
	a = atoi(argv[2]);
	b = atoi(argv[3]);
	printf("cmd :%s\n", str_cmd);
	printf("a   :%d\n", a);
	printf("b   :%d\n", b);
	for(j=0;j<argc;j++)
	{
		printf("%s\n",argv[j]);
	}
	switch(atoi(str_cmd))
	{
		case 0:
		if(strcasecmp(str_cmd, "add")==0)
		{
			result = add(a, b);
			printf("Addition:%d\n", result);
		}
		case 1:
		if(strcasecmp(str_cmd,"mul")==0)
		{
			result=mul(a,b);
			printf("mul:%d\n",result);
		}
		case 2:
		if(strcasecmp(str_cmd,"sub")==0)
		{
			result=sub(a,b);
			printf("sub:%d\n",result);
		}
		case 3:
		if(strcasecmp(str_cmd,"div")==0)
		{
			result=div(a,b);
			printf("div:%d\n",result);
		}
		case 4:
		if(strcasecmp(str_cmd,"mod")==0)
		{
			result=mod(a,b);
			printf("mod:%d\n",result);
		}
	}
}
int add(int c,int d)
{
	int e;
	e=c+d;
	return e;
}
int mul(int c,int d)
{
	int e;
	e=c*d;
	return e;
}
int sub(int c,int d)
{
	int e;
	e=c-d;
	return e;
}
int div(int c,int d)
{
	int e;
	e=c/d;
	return e;
}
int mod(int c,int d)
{
	int e;
	e=c%d;
	return e;
}	



