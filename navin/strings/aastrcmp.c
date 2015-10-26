#include<stdio.h>
// #include<string.h>

int astrcmp(char *c,char *d);


int main()
{
    int k;
	char a[20]="Ravin",b[15]="ravin";
	//int n=5;


 k=astrcmp(a,b);

if(k==1) 
     printf("String 1 is big");
if(k==0)	
	 printf("Both are equal");
if(k==-1)   
	  printf("String 2 is big"); 


}


/*	if(a==b)   
		printf(" \n %s is equal to %s\n" ,a,b ) ;        
	else
		printf("\n %s is not equal to %s \n " ,a,b ) ;
  if(a>=b) 
     {
        if(a>b)
          return 1;
		 else 
          return 0;
     }
	  else
	    return -1;  
	


 int astrcmp(char *c,char *d)
{
	int i=0,j=0,k=5;

    
   for(i=0;c[i]!='\0'&&d[i]!='\0';i++)
      {
	     	 
		for(j=0;d[i]!='\0';i++)
    		 if(d[i]==c[i]);
	  }
	  
   
   if(i>=j) 
    {
      if(i>j)
	    return 1;
	  else 
	    return 0;
    }
	else
	  return -1; 
	  
	  */


