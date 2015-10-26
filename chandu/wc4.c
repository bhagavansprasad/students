int word_count (char *buffer)
{
	int k=0,count=0;
	for(k=0;buffer[k]='\0';k++)
	{
		if ((buffer[k]!=' ')&&(buffer[k+1]=='\0')||(buffer[k]!=' ')&&(buffer[k+1]==' '))
		{
			count++;
		}
	}
	return(count);
}
