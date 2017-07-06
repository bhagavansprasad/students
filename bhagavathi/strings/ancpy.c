char astcpy(char *d,char *s)
{
	int i=0;
	for(i=0; s[i] != '\0'; i++)
	{
		d[i]=s[i];
	}
	d[i]='\0';
	return d[i];
}

