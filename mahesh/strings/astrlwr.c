void astrlwr(char *p)
{
	int i;
	for(i=0;p[i];i++)
	{
		if(p[i]>=65&&p[i]<=90)
			p[i]=p[i]+32;
	}
}
