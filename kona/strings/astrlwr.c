void astrlwr(char *s1)
{
	int i;
	for(i=0;s1[i];i++)
	{
		if(s1[i]>=65 &&s1[i]<=90)
			s1[i]=s1[i]+32;
	}		
}
