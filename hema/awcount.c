int get_wcount(char *p)

{
	int i=0,wcount=0;

	for(i=0;p[i]!='\0';i++)
	{
		while(p[i]==' ' );
		i++;

		if(p[i]!=' '&&p[i]!='\0')
			wcount++;

		while(p[i]!=' ' && p[i]!='\0')
			i++;
	}
	return wcount;
}

