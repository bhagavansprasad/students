char astrncat(char *d,char *s,int l)
{
	int i=0, j=0;
	for(i=0; i<=l && d[i] != '\0'; i++)
	for(j=0; s[i] != '\0'; j++,i++)
	d[i]=s[i];
	return d[i];	
}

