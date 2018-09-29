int astrcmp(char *s,char*d)
{
	int i;
	for(i=0;s[i]==d[i];i++)
	{
		if(s[i]=='\0')
		return	0;
	}
	
return ( s[i]-d[i]);
}
