int astrncmp(char *c,char *d, int n)
{
	int i=0;
	for(i=0; i<=n && c[i] !='\0'; i++)
	{
		if(c[i] != d[i])
			return 0;
	}
			return 1;
}
