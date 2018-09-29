#include<stdio.h>
main()
{
int s1=40,s2=50,s3=30,a;
if(s1>=35)
	{
	  if(s2>=35)
	    { 
		  if(s3>=35)
		    {
			 a=1;
			 }
         }
	 }
  if(a==1)
  printf("promoted\n");
  else
  printf("not promoted\n");
}
