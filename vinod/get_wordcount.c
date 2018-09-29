int get_wordcount(char *a)
{
	int i,c=0;

	for(i = 0; a[i] !='\0'; i++)
	{
		if(a[i] !=' ' && a[i] != '\0')
		{
			for( ; a[i+1] !=' ' && a[i+1] != '\0'; i++);
			c++;
		}
	}

	return c;
}
