char *astrcpy(char *d, char *s)
{
	int i = 0;
	for (i = 0; (d[i] = s[i]) ; i++);
	d[i] = '\0';
	return d[i];
}
