void astrupr(char *s1)
{
	int i;
	for(i=0;s1[i];i++)
	{
		if(s1[i]>=97 &&s1[i]<=122)
			s1[i]=s1[i]-32;
	}		
}
