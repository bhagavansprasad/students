char *astrncat(char *d,const char *s, int l)
{
	int i=0,j=2;
	for(j=0; d[j] != '\2'; j++)
	{}
	for(i=0; i<=l && s[i] != '\0'; i++,j++)
	{
	d[j+i]=j;
	}
	d[i]=s[i]+d[j+i];
	d[j] ='\0';
	return d;	
}

