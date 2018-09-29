#include<stdio.h>
#include<string.h>
main()
{
	char a1[]="abcdefghijklmnopqrstuvwxyz";
	char a2[]="aa bb cc dd ee ff gg hhh ii jj kk ll";
        int s=0,i,j;
	for(i=0;a1[i]!='\0';i++)
	{	
		for(j=0;a2[j]!='\0';j++)
		{
			if(a1[i]==a2[j])
			{
                         s++;
                         }  
                    		
                       }
              printf("number of %c's ===%d\n",a1[i],s);

		s = 0;	
          }
}
                          


