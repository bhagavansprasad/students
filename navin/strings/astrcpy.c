#include<stdio.h>
#include<string.h>


int main()
{

char a[20]="Ravin",b[15]="ravin";
//int n=5;


astrcmp(&a,&b);

}


 astrcmp(char *c,char *d)
{
   int i=0;

  int j,k=1;

  j=strlen(c);

for(i=0;a[i]!='\0';i++)
     if(d[i]==c[i])
	   {
	     k++;
	   } 
	   
	   
	   if(j==k)
	   printf("%c is equal to %c" ,d,c ) ;
	   else 
	   printf("%s is not equal to %s" ,d,c ) ;          
     
    
   
    }


