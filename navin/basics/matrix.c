#include <stdio.h>
main()
{
int a[3][3]={1,2,3,4,5,6,1,2,3};
int b[3][3]=(1,2,3,4,0,4,1,2,3);
int i,j,k,c[3][3],m=0;

for(i=;i<3;i++)
  {
   for(j=0;j<3;j++)
      {
	 	   m+=a[i][j]*b[i][j];
	  }
	    c[i][i]=m;

   printf("%d",c[i][j]);
  }

}
