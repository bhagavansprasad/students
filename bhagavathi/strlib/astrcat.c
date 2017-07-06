char astrcat(char *d,char *s)
{
	int i=0, j=0;
	for(i=0; d[i] != '\0'; i++);
		for(j=0; s[j] != '\0'; j++,i++)
			d[i]=s[j];
	return d[i];	
}

