char *a_strcpy(char *dest,const char *src)
{
	int i;
	for(i=0 ; (dest[i]=src[i]) ; i++);
	return (char*)dest;
}
