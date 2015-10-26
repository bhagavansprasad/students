#include<stdio.h>

int get_word_count(char sp[], char p)
{
	int i=0, wc = 0;

	if(p!=' ' && sp[i]!=' ')
	{
	  if(p!='\n' && sp[i]!='\n' && p!='\t' && sp[i]!='\t')    
	  {
		wc--;
		printf("p wc:%d\n",wc);

       }		
 	}

	for ( i=0  ; sp[i] == ' '; i++);

	for( ; sp[i]!='\0'; i++)
	{
		if(sp[i] == ' ')
		{
			if(sp[i-1] != ' ')
	        { 
			  if(sp[i-1]!='\n' && sp[i-1]!='\t')
			{
				wc++;
				printf("main wc:%d\n",wc);

			}
		   } 	
		}
	}
	if (sp[i] == '\0' )
	{
	    if(sp[i-1]!=' ' && sp[i-1]!='\n' && sp[i-1]!='\t')  
		{
	  	   wc++;
		   printf("null wc:%d\n",wc);

	 	}
   
   /* 	if(sp[i-1]=='\n'  && sp[i-2]==' ')
		{
		  wc--;
		}      
		if(sp[i-1]=='\n'  )
		 {
		   if(i!=1  &&  sp[i-2]!=' ')
		  {
		    wc++;
		  }
		 } */
	}	

	for(i=1;sp[i]!='\0';i++)
	{	
		if(sp[i]=='\n' && sp[i-1]!=' ' && sp[i-1]!='\n'  && sp[i-1]!='\t')
		{
			wc++;
			printf("n wc:%d\n",wc);
		}
	}

	
	for(i=1;sp[i]!='\0';i++)
	{	
		if(sp[i]=='\t' && sp[i-1]!=' ' && sp[i-1]!='\t'  && sp[i-1]!='\n')
		{
			wc++;
			printf("t wc:%d\n",wc);

		}
	}	

	
/*	for(i=0;sp[i]!='\0';i++)
	{
	  if(sp[i-1]=='\n' )
	  {
	   if(i!=1  && sp[i-2]!=' ')
	  {
	    wc++;
	  }
	  }
    }  */  
/*	for(i=0;sp[i]!='\0';i++)
	{
	  if(sp[i]=='\n' && i==0)
	  {
	    wc--;
	    printf("i:%d\n",i);
	   }

     }  */
	return wc;
}
