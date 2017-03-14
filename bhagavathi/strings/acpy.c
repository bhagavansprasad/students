int astncpy(char *d,char *s,int l)
{
	int i=0;
	for(i=0; i<=l && s[i] != '\0'; i++)
	{
		d[i]=s[i];
	}
	d[i]='\0';
	return d[i];
}
