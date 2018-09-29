int astrlen(char *pname)
{
	int i;

	for(i=0 ; pname[i]!='\0' ;i++);

	return i;
}
