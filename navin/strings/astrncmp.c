#include<stdio.h>
#include<string.h>


int main()
{

	char a[25]="ravin is a good boy",b[29]="ravin is Good boy";
int n=18;

	astrcmp(&a,&b,n);

}


astrcmp(char *c,char *d, int n)
{
	int i=0,j=0,k=5;


	for(i=0;i<n;i++)
		if(d[i]==c[i])
			j++;


	if(j==n)   
		printf(" \n %s is equal to %s\n" ,d,c ) ;        
	else
		printf("\n %s is not equal to %s \n " ,d,c ) ;


}


