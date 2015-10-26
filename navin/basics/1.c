#include <stdio.h>
main()
{
  int a[3][3]={1,2,3,4,5,6,1,2,3};
  int b[3][3]={1,2,3,4,0,4,1,2,3};
  int c[3][3],i,j,k,l;

for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
	  {
	    l=0;
         for(k=0;k<3;k++)
		  {
		   
	       l+=a[i][k]*b[k][j];
	         
       }
	    c[i][j]=l;

      }		
   }


for(i=0;i<3;i++)

   {
   for(j=0;j<3;j++)
    {

  printf(" %d ",c[i][j]);
    }
printf("\n");

  }

}  


  
