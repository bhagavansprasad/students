int line_count(char *p)
{
	int i,count=1;

	for(i=0;p[i]!='\0';i++) 
	{
		if(p[i]=='\n')
			count+=1;
	}	
	return count;
}
