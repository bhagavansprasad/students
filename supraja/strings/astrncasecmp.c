int astrncasecmp(char *s1,char *s2,int n)
{
	int i,w;
	for(i=0;s1[i]&&s2[i]&&i<=n-1;i++)
	{
		if(intatolower(s1[i])==intatolower(s2[i]))
		{
			w=0;
		}
		else
		{
			w=-1;
			break;
		}
	}
	return (w);
}
