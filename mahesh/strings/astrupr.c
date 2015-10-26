void astrupr(char *p)
{
	int i;
	for(i=0;p[i];i++)
	{
		if(p[i]>=97&&p[i]<=122)
			p[i]=p[i]-32;
	}
}
