#include<stdio.h>
int add (int x,int y);
int prod(int x,int y);
int diff(int x,int y);
int div(int x,int y);
int mod(int x,int y);
main(int argc,char *argv[])
{
	int i,j,k=0,b,c[2]={0,0},d,m,neg=0;
	char a,s1[]="add",s2[]="prod",s3[]="diff",s4[]="div",s5[]="mod";
	
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
			b=atoi(a);
			printf("b:%d\n",b);
			if(b!=45)
			{
				c[k]=c[k]*10+b;
			}
			else
			{
				neg=1;
			}	
		}
		if(neg==1)
		{
			c[k]=0-c[k];
		}
		printf("c[%d]=%d\n",k,c[k]);

		k++;
		neg=0;
	}
	if(strcasecmp(argv[1],s1)==0)
	{
		d=add(c[0],c[1]);
		printf("Addition:%d\n",d);
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

