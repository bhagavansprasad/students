#include<stdio.h>
#include<string.h>
char strings[10][100] = { 
	"add 10 20",
	"mul 30 3",
	"div 100 5",
	"sub 234 34",
	"mod 234 5"
};

#if 0
	if(strcasecmp(argv[1],s1)==0)
	{
		d=add(c[0],c[1]);
		printf("Addition:%d\n",d);
	}	
	if(strcasecmp(argv[1],s2)==0)
	{
		d=mul(c[0],c[1]);
		printf("Product:%d\n",d);
	}
	if(strcasecmp(argv[1],s3)==0)
	{
		d=sub(c[0],c[1]);
		printf("Difference:%d\n",d);
	}
	if(strcasecmp(argv[1],s4)==0)
	{
		d=div(c[0],c[1]);
		printf("Quotient:%d\n",d);
	}
	if(strcasecmp(argv[1],"mod")==0)
	{
		d=mod(c[0],c[1]);
		printf("Remainder:%d\n",d);
	}
}
#endif
int add(int x,int y)
{
	int z;
	z=x+y;
	return z;
}
int mul(int x,int y)
{
	int z;
	z=x*y;
	return z;
}
int sub(int x,int y)
{
	int z;
	z=x-y;
	return z;
}
int div(int x,int y)
{
	int z;
	z=x/y;
	return z;
}
int mod(int x,int y)
{
	int z;
	z=x%y;
	return z;
}	

int parse_string(char *pstr, char *pcmd, int *pa, int *pb)
{
	//"mul 30 3",
	//TODO: parse string 'pstr' and fill pcmd, pa and pb
}

main()
{
	int i =0;
	char str_cmd[128];
	int a = 0;
	int b = 0;

	for (i = 0; i < sizeof(strings)/sizeof(strings[0]); i++)
	{
		printf("%d. %s\n", i+1, strings[i]);

		parse_string(strings[i], str_cmd, &a, &b)

		printf("cmd :%s, a :%d, b :%d\n", str_cmd, a, b);
	}
}


