char *astrtotoggale(char *ptr)
{
	int i;
	for(i=0;ptr[i]!='\0';i++)
	{
	   if(ptr[i]==' ')
	   {
	    ptr[i]=' ';
		}
		else
		{
		if(ptr[i]>=65&&ptr[i]<=90)
		{
			ptr[i]=ptr[i]+32;
	    }   
         else
		{
			ptr[i]=ptr[i]-32;
		}
		}
	}	
		return (ptr);
}
	
