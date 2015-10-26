int astrncasecmp (char *s1, char *s2, int n)
{
	//char atoupper(char ch);
	int i ;
	int c = 0;
	for (i = 0; s1[i] && s2[i] && i < n; i++ )
	{
		c = (atoupper(s1[i]) - atoupper(s2[i]));
	}

	return c;
}


