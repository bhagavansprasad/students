#include<stdio.h>
#include<string.h>

										char strings[10][100] = {
														"add 10 20",
														"Add 200 2",
														"mul 30 3",
														"div 100 5",
														"sub 234 34",
														"mod 234 5"
																	};

int add(int x,int y);
float fadd(float x,float y);
int prod(int x,int y);
float fprod(float x,float y);
int sub(int x,int y);
float fsub(float x,float y);
int div(int x,int y);
float fdiv(float x,float y);
int mod(int x,int y);
//float fmod(float x,float y);

		
/*int evoluate_string(char *str)
{
	char cmd[100];
	int val1 = 0, val2 = 0;

	parse_command(str, cmd)
	parse_arguments(str, &val1, val2);

	if (strncasecmp(cmd, "add") == 0);
	{
		res = add(val1, val2)
		print("res :%d\n", res);
	}
	else if (strncasecmp(cmd, "add") == 0);
	{
	}
}

main(int argc,char *argv[])
{
	t = astr_atoi("234");
	for(i=0; i < 6; i++)
	{
		printf("%d. %s\n", i+1, strings[i]);
		evoluate_string(strings[i]);
	}*/


main(int argc,char *argv[])
{
	int i,j,k=0,b,c[2]={0,0},d,m,neg=0,point=0,f=0;
	char a,s1[]="add",s2[]="prod",s3[]="diff",s4[]="div",s5[]="mod";
	float res,fl[2]={0,0};
	
	for(m=0;m<argc;m++)
	{
		printf("%s\n",argv[m]);
	}	

	for(j=2;j<argc;j++)
	{
		for(i=0;*(argv[j]+i)!='\0';i++)
		{
			a=*(argv[j]+i);
			printf("a:%c\n",a);
			b=aatoi(a);
			printf("b:%d\n",b);
			point=point*10;
			if(b>=0 && b<=9)
			{
				c[k]=c[k]*10+b;
			}
			if(b==45)
			{
				neg=1;
			}
			if(b==46)
			{
				point=1;
			}	
		}
		if(neg==1)
		{
			c[k]=0-c[k];
		}
		if(point!=0)
		{
			fl[k]=c[k];
			fl[k]=fl[k]/point;
			f=1;
		}	
		printf("c[%d]=%d\n",k,c[k]);
		printf("fl[%d]=%f\n",k,fl[k]);

		k++;
		neg=0;
		point=0;
	}
	if(fl[0]!=0  &&  fl[1]==0)
	{
		fl[1]=c[1];
	}
	if(fl[0]==0  &&  fl[1]!=0)
	{
		fl[0]=c[0];
	}	
	
	if(strcasecmp(argv[1],s1)==0)
	{
		if(f==1)
		{
			res=fadd(fl[0],fl[1]);
			printf("Addition:%f\n",res);
		}
		else
		{
			d=add(c[0],c[1]);
			printf("Addition:%d\n",d);
		}	
	}
	if(strcasecmp(argv[1],s2)==0)
	{
		d=prod(c[0],c[1]);
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

int add(int x,int y)
{
	int z;
	z=x+y;
	return z;
}
float fadd(float x,float y)
{
	float z;
	z=x+y;
	return z;
}


int prod(int x,int y)
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
float fprod(float x,float y)
{
	float z;
	z=x*y;
	return z;
}

float fsub(float x,float y)
{
	float z;
	z=x-y;
	return z;
}

float fdiv(float x,float y)
{
	float z;
	z=x/y;
	return z;
}

/*float fmod(float x,float y)
{
	float z;
	z=x%y;
	return z;
}*/	



