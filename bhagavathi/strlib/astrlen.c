int astrlen(char *a)
{
	int i=0;
	for(i=0; a[i] != '\0'; i++);

	return i;
}
