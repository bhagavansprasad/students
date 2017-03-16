int astrncpy(char *a,char *b,int l)
{
	int i=0;
	for(i=0; i<=l && b[i] != '\0'; i++)
		a[i]=b[i];
		a[i] = '\0';
	return a[i];
}
