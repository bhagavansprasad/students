int get_linecount(char *p)
{
	int i, c=1;
	for(i=0 ; p[i] ; i++)
	{
		if(p[i]== '\n')
			c++;
	}
	return c;
}
