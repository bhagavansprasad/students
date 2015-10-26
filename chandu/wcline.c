int line_count(char*a)
{  
int i=0,count=0;
    for(i=0;a[i]!='\0';i++)
	{ 
	    if (a[i]=='\n')
		{ 
		   count++;
		}
	}
	return(count);
}
