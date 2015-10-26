char *astrncpy(char *d, char *s, int n)
{
	int i;

	for(i=0; s[i] !='\0' && i < 10; i++)
	{
		d[i]=s[i];
	}

	d[i]='\0';

	return d;
}
