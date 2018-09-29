int astrncmp(char *s1,char *s2,int n)
{
	int i,c=0;
	for(i=0; i<n && s1[i]!='\0' && s2[i]!='\0';i++)
	{
		if (s1[i]!=s2[i])
		{
			c=1;
			break;
		}
	}

	if ((s1[i] != '\0' && s2[i] == '\0') || (s1[i] == '\0' && s2[i] != '\0'))
	
	c=1;
	return (c);
}
