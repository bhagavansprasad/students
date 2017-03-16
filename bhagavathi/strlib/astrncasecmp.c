int astrncasecmp (char *a,char *b,int l)
{
	int i=0;
	for(i=0; i<=l && a[i] != '\0'; i++)
	{
		if(tolower(a[i]) != tolower(b[i]))
			return 0;
	}
	return 1;
}
