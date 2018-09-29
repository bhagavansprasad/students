char lwr( char );
int astrncasecmp(char *s1,char *s2,int n)
{
	int i , rv;

	char p3 , p4;

	for (i=0; i<n && (s1[i] != '\0' && s2[i] != '\0'); i++)
	{
		p3 = lwr(s1[i]);

		p4 = lwr(s2[i]);

		if(p3 != p4)
		{
			rv = 1;
			break;
		}
	}
}
char lwr( char l)
{
	if (l >= 65 && l <= 90)
		l = l+32;

	return(l);
}
