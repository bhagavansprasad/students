int astrcasecmp(char *s1,char *s2)
{
	int i, w ;

	for(i = 0; s1[i] && s2[i]; i++)
	{
		if(astrtolower(s1[i]) == astrtolower(s2[i]))
		{
		w=0;
		}
		else
		{
			w = -1;
			break;
		}
	}

	return (w);
}
