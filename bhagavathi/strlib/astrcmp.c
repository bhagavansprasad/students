int astrcmp(char *a,char *b)
{
	int i=0 ;
	
	for(i=0; b[i] !='\0'; i++)
	{
		if( a[i] != b[i] || a[i] == '\0' )
			return 0;
	}
	return 1;
}

