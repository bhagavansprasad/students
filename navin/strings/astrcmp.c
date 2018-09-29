#include<stdio.h>
#include<string.h>


int main()
{

	char a[20]="Ravin",b[15]="ravin";
	//int n=5;


	astrcmp(&a,&b);

	if(a==b)   
		printf(" \n %s is equal to %s\n" ,a,b ) ;        
	else
		printf("\n %s is not equal to %s \n " ,a,b ) ;

/*   if(a>=b) 
     {
        if(a>b)
          return 1;
		 else 
          return 0;
     }
	  else
	    return -1;  */

}		

astrcmp(char *c,char *d)
{
	int i=0,j=0,k=5;


	for(i=0;c[i]!='\0';i++)
	{
		if(d[i]==c[i])
			j++;

	}
	
}


