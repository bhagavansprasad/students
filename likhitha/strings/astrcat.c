int astrcat(char *dest, char *src)
{
	int i,j;
	for(i=0 ; src[i]!='\0' ;i++);
	for(j=0 ; dest[j]!='\0' ;j++,i++)
	{
		src[i]=dest[j];
	}
	src[i]='\0';
	return i;
}

