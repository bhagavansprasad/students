int astrcasecmp(const char *a,const char *b)
{
	int i=0;
		for(i=0; a[i] != '\0'; i++)
		{
			if( tolower(a[i]) != tolower(b[i]))
						return 0;
		}
     return 1;
}

