int astrcpy(char *d,char *s)
{
	int i=0;
	int x=0,n=15;
	for(i=0; i<=n && s[i] != '\0'; i++)
	{
		

		d[i]=s[i];
	}

	d[i]='\0';
   	return i;
}
